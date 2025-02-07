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
package ghidra.app.util.bin.format.elf.relocation;

import ghidra.app.util.bin.format.elf.*;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Program;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.mem.MemoryAccessException;
import ghidra.program.model.symbol.SymbolTable;
import ghidra.program.model.reloc.RelocationResult;
import ghidra.program.model.reloc.Relocation.Status;
import ghidra.util.exception.NotFoundException;

public class eBPF_ElfRelocationHandler extends ElfRelocationHandler {
    @Override
    public boolean canRelocate(ElfHeader elf) {
        return elf.e_machine() == ElfConstants.EM_BPF;
    }

    @Override
    public RelocationResult relocate(ElfRelocationContext elfRelocationContext, ElfRelocation relocation, Address relocationAddress) throws MemoryAccessException, NotFoundException {
        ElfHeader elf = elfRelocationContext.getElfHeader();
        if (elf.e_machine() != ElfConstants.EM_BPF) {
            return RelocationResult.FAILURE;
        }

        Program program = elfRelocationContext.getProgram();
        Memory memory = program.getMemory();

        int type = relocation.getType();
        int symbolIndex = relocation.getSymbolIndex();
        long value;
        boolean appliedSymbol = true;
	int byteLength = 4; // most relocations affect 4-bytes (change if different)

        if (type == 1) {
            try {
                int SymbolIndex = relocation.getSymbolIndex();
                ElfSymbol Symbol = elfRelocationContext.getSymbol(SymbolIndex);
                String map = Symbol.getNameAsString();

                SymbolTable table = program.getSymbolTable();
                Address mapAddr = table.getSymbols(map).next().getAddress();
                String sec_name = elfRelocationContext.relocationTable.getSectionToBeRelocated().getNameAsString();
                if (sec_name.toString().contains("debug")) {
                return RelocationResult.SKIPPED;
                }

                value = mapAddr.getAddressableWordOffset();
                Byte dst = memory.getByte(relocationAddress.add(0x1));
                memory.setLong(relocationAddress.add(0x4), value);
                memory.setByte(relocationAddress.add(0x1), (byte)(dst + 0x10));
            }
            catch(NullPointerException e) {}
        } else if (type == 10) {
            try {
                int SymbolIndex = relocation.getSymbolIndex();
                ElfSymbol Symbol = elfRelocationContext.getSymbol(SymbolIndex);
                String func_or_sec = Symbol.getNameAsString();
                long instr_next = relocationAddress.add(0x8).getAddressableWordOffset();

                // if we have, e.g, non-static function, it will be marked in the relocation table
                // and indexed in the symbol table and it's easy to calculate the pc-relative-offset.
                if (Symbol.isFunction()) {
                    SymbolTable table = program.getSymbolTable();
                    Address funcAddr = table.getSymbols(func_or_sec).next().getAddress();
                    String sec_name = elfRelocationContext.relocationTable.getSectionToBeRelocated().getNameAsString();
                    if (sec_name.toString().contains("debug")) {
                        return RelocationResult.SKIPPED;
                    }
                    value = funcAddr.getAddressableWordOffset();
                    int offset = (int)(value - instr_next);
                    memory.setInt(relocationAddress.add(0x4), offset);
                }
                // If we're dealing with static function we'll get the section name where it's located
                else if (Symbol.isSection()) {
                    if (memory.getInt(relocationAddress) == 0x1085) {

                        ElfSectionHeader sec = elfRelocationContext.getElfHeader().getSection(func_or_sec);
                        long sec_start = program.getImageBase().getOffset() + sec.getVirtualAddress();

                        // getting call instruction offset (current imm)
                        int current_imm = memory.getInt(relocationAddress.add(0x4));

                        // calculate the call target section offset
                        // according to formula on "kernel.org" docs: https://www.kernel.org/doc/html/latest/bpf/llvm_reloc.html
                        int func_sec_offset = (current_imm + 1) * 8;
                        long func_addr = sec_start + func_sec_offset;
                        int offset = (int)(func_addr - instr_next);
                        memory.setInt(relocationAddress.add(0x4), offset);
                    }
                }
            } catch(NullPointerException e) {}
        }
        if (appliedSymbol && symbolIndex == 0) {
            markAsWarning(program, relocationAddress, Long.toString(type), "applied relocation with symbol-index of 0", elfRelocationContext.getLog());
	}
	return new RelocationResult(Status.APPLIED, byteLength);
    }
}
