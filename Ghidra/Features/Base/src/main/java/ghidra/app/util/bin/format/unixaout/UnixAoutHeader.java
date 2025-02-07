/* ###
 * IP: GHIDRA
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package ghidra.app.util.bin.format.aout;

import java.io.IOException;

import ghidra.app.util.bin.BinaryReader;
import ghidra.app.util.bin.ByteProvider;

public class UnixAoutHeader {

    enum ExecutableType {
        OMAGIC, NMAGIC, ZMAGIC, QMAGIC, CMAGIC, UNKNOWN
    }

    private long binarySize;
    private ExecutableType exeType;
    private boolean machineTypeValid;
    private String languageSpec;
    private String compilerSpec = "default";
    private long pageSize;

    private boolean isNetBSD = false;
    private boolean isSparc = false;

    private long a_magic;
    private long a_text;
    private long a_data;
    private long a_bss;
    private long a_syms;
    private long a_entry;
    private long a_trsize;
    private long a_drsize;

    private long txtOffset;
    private long datOffset;
    private long txtRelOffset;
    private long datRelOffset;
    private long symOffset;
    private long strOffset;

    private long txtAddr;
    private long txtEndAddr;
    private long datAddr;
    private long bssAddr;

    // The Linux implementation of a.out support might have a different header
    // size, but it looks as though that might be caused by a strange mix of
    // 32- and 64-bit integers being padded out in the struct. The intended
    // size seems to be eight 32-bit words (32 bytes total.)
    private static final int sizeOfExecHeader = 32;

    /**
     * Interprets binary data as an exec header from a UNIX-style a.out executable,
     * and validates the contained fields.
     *
     * @param provider       Source of header binary data
     * @param isLittleEndian Flag indicating whether to interpret the data as
     *                       little-endian.
     * @throws IOException
     */
    public UnixAoutHeader(ByteProvider provider, boolean isLittleEndian) throws IOException {
        BinaryReader reader = new BinaryReader(provider, isLittleEndian);

        this.a_magic = reader.readNextUnsignedInt();
        this.a_text = reader.readNextUnsignedInt();
        this.a_data = reader.readNextUnsignedInt();
        this.a_bss = reader.readNextUnsignedInt();
        this.a_syms = reader.readNextUnsignedInt();
        this.a_entry = reader.readNextUnsignedInt();
        this.a_trsize = reader.readNextUnsignedInt();
        this.a_drsize = reader.readNextUnsignedInt();
        this.binarySize = reader.length();

        checkExecutableType();

        // NOTE: In NetBSD/i386 examples of a.out, the "new-style" 32-bit a_magic/midmag word
        // is written in big-endian regardless of the data endianness in the rest of the file.
        if ((this.exeType == ExecutableType.UNKNOWN) && isLittleEndian) {
            this.a_magic = Integer.reverseBytes((int)this.a_magic);
            checkExecutableType();
        }

        checkMachineTypeValidity(isLittleEndian);
        determineTextOffset(isLittleEndian);

        this.datOffset = this.txtOffset + this.a_text;
        this.txtRelOffset = this.datOffset + this.a_data;
        this.datRelOffset = this.txtRelOffset + this.a_trsize;
        this.symOffset = this.datRelOffset + this.a_drsize;
        this.strOffset = this.symOffset + this.a_syms;

        determineTextAddr();
        this.txtEndAddr = this.txtAddr + this.a_text;
        this.datAddr = (this.exeType == ExecutableType.OMAGIC) ?
                this.txtEndAddr : segmentRound(this.txtEndAddr);
        this.bssAddr = this.datAddr + this.a_data;
    }

    /**
     * Returns the processor/language specified by this header.
     */
    public String getLanguageSpec() {
        return this.languageSpec;
    }

    /**
     * Returns the compiler used by this executable. This is left as 'default' for
     * all machine types other than i386, where it is assumed to be gcc.
     */
    public String getCompilerSpec() {
        return this.compilerSpec;
    }

    /**
     * Returns the enumerated type of executable contained in this A.out file.
     */
    public ExecutableType getExecutableType() {
        return this.exeType;
    }

    /**
     * Returns an indication of whether this header's fields are all valid; this
     * includes the machine type, executable type, and section offsets.
     */
    public boolean isValid() {
        return isMachineTypeValid() &&
                (this.exeType != ExecutableType.UNKNOWN) &&
                areOffsetsValid();
    }

    public long getTextSize() {
        return this.a_text;
    }

    public long getDataSize() {
        return this.a_data;
    }

    public long getBssSize() {
        return this.a_bss;
    }

    public long getSymSize() {
        return this.a_syms;
    }

    public long getEntryPoint() {
        return this.a_entry;
    }

    public long getTextRelocSize() {
        return this.a_trsize;
    }

    public long getDataRelocSize() {
        return this.a_drsize;
    }

    public long getTextOffset() {
        return this.txtOffset;
    }

    public long getDataOffset() {
        return this.datOffset;
    }

    public long getTextRelocOffset() {
        return this.txtRelOffset;
    }

    public long getDataRelocOffset() {
        return this.datRelOffset;
    }

    public long getSymOffset() {
        return this.symOffset;
    }

    public long getStrOffset() {
        return this.strOffset;
    }

    public long getTextAddr() {
        return this.txtAddr;
    }

    public long getDataAddr() {
        return this.datAddr;
    }

    public long getBssAddr() {
        return this.bssAddr;
    }

    /**
     * Checks the magic word in the header for a known machine type ID, and sets the
     * languageSpec string accordingly.
     */
    private void checkMachineTypeValidity(boolean readingAsLittleEndian) {

        this.machineTypeValid = true;
        this.pageSize = 4096;
        final short machtype = (short) ((this.a_magic >> 16) & 0xFF);
        final String readEndianness = readingAsLittleEndian ? "LE" : "BE";

        switch (machtype) {
            /**
             * Motorola 68K family
             */
        case UnixAoutMachineType.M_68010:
            this.languageSpec = "68000:BE:32:MC68010";
            break;
        case UnixAoutMachineType.M_68020:
            this.languageSpec = "68000:BE:32:MC68020";
            break;
        case UnixAoutMachineType.M_M68K_NETBSD:
            this.pageSize = 8192;
        case UnixAoutMachineType.M_M68K4K_NETBSD:
            this.isNetBSD = true;
            this.languageSpec = "68000:BE:32:default";
            break;

            /**
             * SPARC family
             */
        case UnixAoutMachineType.M_SPARC_NETBSD:
            this.isNetBSD = true;
        case UnixAoutMachineType.M_SPARC:
        case UnixAoutMachineType.M_SPARCLET:
            this.isSparc = true;
            this.pageSize = 8192;
            this.languageSpec = "sparc:BE:32:default";
            break;
        case UnixAoutMachineType.M_SPARC64_NETBSD:
            this.isNetBSD = true;
            this.isSparc = true;
            this.languageSpec = "sparc:BE:64:default";
            break;

            /**
             * MIPS family
             */
        case UnixAoutMachineType.M_PMAX_NETBSD:
            this.isNetBSD = true;
        case UnixAoutMachineType.M_MIPS1:
        case UnixAoutMachineType.M_MIPS2:
        case UnixAoutMachineType.M_R3000:
            this.languageSpec = "MIPS:LE:32:default";
            break;
        case UnixAoutMachineType.M_MIPS:
            this.languageSpec = "MIPS:BE:32:default";
            break;

            /**
             * National Semiconductor NS32000 family
             */
        case UnixAoutMachineType.M_532_NETBSD:
            this.isNetBSD = true;
        case UnixAoutMachineType.M_NS32032:
        case UnixAoutMachineType.M_NS32532:
            this.languageSpec = "UNKNOWN:LE:32:default";
            break;

            /**
             * x86 family
             */
        case UnixAoutMachineType.M_386_NETBSD:
            this.isNetBSD = true;
        case UnixAoutMachineType.M_386:
        case UnixAoutMachineType.M_386_DYNIX:
            this.compilerSpec = "gcc";
            this.languageSpec = "x86:LE:32:default";
            break;
        case UnixAoutMachineType.M_X86_64_NETBSD:
            this.compilerSpec = "gcc";
            this.languageSpec = "x86:LE:64:default";
            break;

            /**
             * ARM family
             */
        case UnixAoutMachineType.M_ARM6_NETBSD:
            this.isNetBSD = true;
        case UnixAoutMachineType.M_ARM:
            this.languageSpec = "ARM:" + readEndianness + ":32:default";
            break;
        case UnixAoutMachineType.M_AARCH64:
            this.languageSpec = "AARCH64:" + readEndianness + ":64:default";
            break;

            /**
             * RISC family
             */
        case UnixAoutMachineType.M_OR1K:
            this.languageSpec = "UNKNOWN:BE:32:default";
            break;
        case UnixAoutMachineType.M_RISCV:
            this.languageSpec = "RISCV:LE:32:default";
            break;
        case UnixAoutMachineType.M_HPPA_OPENBSD:
            this.languageSpec = "pa-risc:BE:32:default";
            break;

            /**
             * PowerPC family
             */
        case UnixAoutMachineType.M_POWERPC_NETBSD:
            this.isNetBSD = true;
            this.languageSpec = "PowerPC:" + readEndianness + ":32:default";
            break;
        case UnixAoutMachineType.M_POWERPC64:
            this.languageSpec = "PowerPC:" + readEndianness + ":64:default";
            break;

            /**
             * SuperH family
             * NOTE: It's unclear if there is support for SuperH SH-3 or SH-5 cores;
             * the primary SuperH language seems to support SH-1 and SH-2 variants
             * and the alternative is the SuperH4 language.
             */
        case UnixAoutMachineType.M_SH3:
        case UnixAoutMachineType.M_SH5_32:
            this.languageSpec = "SuperH:BE:32:default";
            break;
        case UnixAoutMachineType.M_SH5_64:
            this.languageSpec = "SuperH:BE:64:default";
            break;

            /**
             * VAX family
             */
        case UnixAoutMachineType.M_VAX_NETBSD:
            this.pageSize = 512;
        case UnixAoutMachineType.M_VAX4K_NETBSD:
            this.isNetBSD = true;
            this.languageSpec = "UNKNOWN:LE:32:default";
            break;

            /**
             * Other
             */
        case UnixAoutMachineType.M_CRIS:
            this.languageSpec = "UNKNOWN:LE:32:default";
            break;
        case UnixAoutMachineType.M_ALPHA_NETBSD:
            this.isNetBSD = true;
        case UnixAoutMachineType.M_IA64:
            this.languageSpec = "UNKNOWN:" + readEndianness + ":64:default";
            break;
        case UnixAoutMachineType.M_29K:
        case UnixAoutMachineType.M_88K_OPENBSD:
            this.languageSpec = "UNKNOWN:" + readEndianness + ":32:default";
            break;
        case UnixAoutMachineType.M_UNKNOWN:
            this.languageSpec = "UNKNOWN:" + readEndianness + ":32:default";
            break;
        default:
            this.machineTypeValid = false;
        }

        // Check that the detected architecture's endianness matches the endianness
        // with which we're reading the file; if there's a mismatch, clear the
        // machineTypeValid flag because this was evidently a false reading.
        if (this.machineTypeValid) {
            String[] languageTokens = this.languageSpec.split(":");
            if ((languageTokens.length < 2) ||
                    !languageTokens[1].equalsIgnoreCase(readEndianness)) {
                this.machineTypeValid = false;
            }
        }
    }

    /**
     * Returns a flag indicating whether the header contains a known machine type
     * ID.
     */
    private boolean isMachineTypeValid() {
        return this.machineTypeValid;
    }

    /**
     * Returns a flag indicating whether this header contains a representation of a
     * valid executable type.
     */
    private void checkExecutableType() {
        final short exetypeMagic = (short) (this.a_magic & 0xFFFF);

        switch (exetypeMagic) {
        case 0x111: // 0421: core file
            this.exeType = ExecutableType.CMAGIC;
            break;
        case 0x108: // 0410: pure executable
            this.exeType = ExecutableType.NMAGIC;
            break;
        case 0x107: // 0407: object file or impure executable
            this.exeType = ExecutableType.OMAGIC;
            break;
        case 0x0CC: // 0314: demand-paged exe w/ header in .text
            this.exeType = ExecutableType.QMAGIC;
            break;
        case 0x10B: // 0413: demand-paged executable
            this.exeType = ExecutableType.ZMAGIC;
            break;
        default:
            this.exeType = ExecutableType.UNKNOWN;
        }
    }

    /**
     * Determines the offset in the binary file at which the .text segment begins.
     * This routine should attempt to replicate the logic from the N_TXTOFF macro
     * that appears in the different incarnations of a.out.h.
     *
     * NOTE: The FreeBSD imgact_aout.h implies that, if the a_magic word contains
     * ZMAGIC when read as little endian, the file offset for .text is __LDPGSZ;
     * otherwise, if a_magic contains ZMAGIC when read as big endian, the file offset
     * for .text is 0. Indeed, it looks like NetBSD uses big-endian ordering for
     * the a_magic word even when the file contains code for a little-endian
     * processor. This seems strange.
     */
    private void determineTextOffset(boolean isLittleEndian) {

        // Some combinations of executable type and architecture actually include the
        // header in the .text section. This includes QMAGIC type and some (most? all?)
        // big-endian ZMAGICs.
        if ((this.exeType == ExecutableType.QMAGIC) ||
            (this.exeType == ExecutableType.ZMAGIC)) {
            this.txtOffset = 0;

        } else {
            this.txtOffset = sizeOfExecHeader;
        }
    }

    /**
     * Uses the combination of executable type and architecture to set the appropriate
     * base address of the .text segment when loaded.
     */
    private void determineTextAddr() {

        if ((this.isSparc && (this.exeType == ExecutableType.NMAGIC)) ||
            (this.isNetBSD) ||
            (this.exeType == ExecutableType.QMAGIC)) {
            this.txtAddr = this.pageSize;

        } else {
            this.txtAddr = 0;
        }
    }

    /**
     * Returns a flag indicating whether all the file offsets in the header
     * (for the segments of nonzero size) fall within the size of the file.
     */
    private boolean areOffsetsValid() {
        // Note that we can't check the string table validity because, if it
        // doesn't exist, its offset will be computed to be beyond the end of
        // the file. The string table is also not given an explicit size in
        // the header.
        boolean status =
                ((this.a_text == 0)   || (this.txtOffset    < this.binarySize)  &&
                ((this.a_data == 0)   || (this.datOffset    < this.binarySize)) &&
                ((this.a_trsize == 0) || (this.txtRelOffset < this.binarySize)) &&
                ((this.a_drsize == 0) || (this.datRelOffset < this.binarySize)) &&
                ((this.a_syms == 0)   || (this.symOffset    < this.binarySize)));
        return status;
    }

    /**
     * Rounds the provided address up to the next page boundary.
     */
    private long segmentRound(long addr) {
        final long mask = this.pageSize - 1;
        long rounded = ((addr + mask) & ~mask);
        return rounded;
    }
}
