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
package ghidra.app.util.bin.format.elf;

import java.io.IOException;
import java.lang.reflect.Constructor;

import ghidra.app.util.bin.BinaryReader;
import ghidra.app.util.bin.StructConverter;
import ghidra.app.util.bin.format.elf.extend.ElfLoadAdapter;
import ghidra.app.util.bin.format.elf.relocation.ElfRelocationContext;
import ghidra.app.util.bin.format.elf.relocation.ElfRelocationHandler;
import ghidra.program.model.data.*;

/**
 * A class to represent the Elf32_Rel and Elf64_Rel data structure.
 * <br>
 * <pre>
 * typedef uint32_t Elf32_Addr;
 * typedef uint64_t Elf64_Addr;
 * typedef uint32_t Elf32_Word;
 * typedef uint64_t Elf64_Xword;
 * 
 * REL entry:
 * 
 *    typedef struct {
 *        Elf32_Addr   r_offset;
 *        Elf32_Word   r_info;
 *    } Elf32_Rel;
 * 
 *    typedef struct {
 *        Elf64_Addr   r_offset;
 *        Elf64_Xword  r_info;
 *    } Elf64_Rel;
 * 
 * RELA entry with addend:
 * 
 *    typedef struct {
 *        Elf32_Addr    r_offset;
 *        Elf32_Word    r_info;
 *        Elf32_Sword   r_addend;
 *    } Elf32_Rela;
 * 
 *    typedef struct {
 *        Elf64_Addr    r_offset;   //Address
 *        Elf64_Xword   r_info;     //Relocation type and symbol index
 *        Elf64_Sxword  r_addend;   //Addend 
 *    } Elf64_Rela;
 * 
 * RELR entry (see SHT_RELR, DT_RELR):
 *    NOTE: Relocation type is data <i>relative</i> and must be specified by appropriate relocation handler
 *    (see {@link ElfRelocationHandler#getRelrRelocationType()}) since it is not contained within the 
 *    relocation table which only specifies <i>r_offset</i> for each entry.
 * 
 * </pre>
 * 
 * NOTE: instantiation relies on the use of a default constructor which must be 
 * implemented by any extension.  An extension should implement the methods
 * {@link #initElfRelocation(BinaryReader, ElfHeader, int, boolean)} and/or
 * {@link #initElfRelocation(ElfHeader, int, boolean, long, long, long)}.  
 */
public class ElfRelocation implements StructConverter {

	protected static final String R_OFFSET_COMMENT = "location to apply the relocation action";
	protected static final String R_INFO_COMMENT =
		"the symbol table index and the type of relocation";
	protected static final String R_ADDEND_COMMENT =
		"a constant addend used to compute the relocatable field value";

	private static final long BYTE_MASK = 0xFF;
	private static final long INT_MASK = 0xFFFFFFFFL;

	private long r_offset;
	private long r_info;
	private long r_addend;

	private boolean hasAddend;
	private boolean is32bit;
	private int relocationIndex;

	/**
	 * Factory construction and initialization method for a ELF relocation entry
	 * @param reader binary reader positioned at start of relocation entry.
	 * @param elfHeader ELF header
	 * @param relocationIndex index of entry in relocation table
	 * @param withAddend true if if RELA entry with addend, else false
	 * @return ELF relocation object
	 * @throws IOException if an IO or parse error occurs
	 */
	public static ElfRelocation createElfRelocation(BinaryReader reader,
			ElfHeader elfHeader, int relocationIndex, boolean withAddend) throws IOException {
		Class<? extends ElfRelocation> elfRelocationClazz = getElfRelocationClass(elfHeader);
		ElfRelocation elfRelocation = getInstance(elfRelocationClazz);
		elfRelocation.initElfRelocation(reader, elfHeader, relocationIndex, withAddend);
		return elfRelocation;
	}

	/**
	 * GenericFactory construction and initialization method for a ELF representative 
	 * relocation entry 
	 * @param elfHeader ELF header
	 * @param relocationIndex index of entry in relocation table
	 * @param withAddend true if if RELA entry with addend, else false
	 * @param r_offset The offset for the entry
	 * @param r_info The info value for the entry
	 * @param r_addend The addend for the entry
	 * @return ELF relocation object
	 * @throws IOException if an IO or parse error occurs
	 */
	public static ElfRelocation createElfRelocation(ElfHeader elfHeader,
			int relocationIndex, boolean withAddend, long r_offset, long r_info, long r_addend)
			throws IOException {
		Class<? extends ElfRelocation> elfRelocationClazz = getElfRelocationClass(elfHeader);
		ElfRelocation elfRelocation = getInstance(elfRelocationClazz);
		elfRelocation.initElfRelocation(elfHeader, relocationIndex, withAddend, r_offset, r_info,
			r_addend);
		return elfRelocation;
	}

	private static ElfRelocation getInstance(Class<? extends ElfRelocation> elfRelocationClazz)
			throws IOException {
		try {
			Constructor<? extends ElfRelocation> constructor = elfRelocationClazz.getConstructor();
			return constructor.newInstance();
		}
		catch (NoSuchMethodException e) {
			throw new IOException(
				elfRelocationClazz.getName() + " does not provide default constructor");
		}
		catch (Exception e) {
			throw new IOException(e);
		}
	}

	private static Class<? extends ElfRelocation> getElfRelocationClass(ElfHeader elfHeader) {
		Class<? extends ElfRelocation> elfRelocationClass = null;
		ElfLoadAdapter loadAdapter = elfHeader.getLoadAdapter();
		if (loadAdapter != null) {
			elfRelocationClass = loadAdapter.getRelocationClass(elfHeader);
		}
		if (elfRelocationClass == null) {
			elfRelocationClass = ElfRelocation.class;
		}
		return elfRelocationClass;
	}

	/**
	 * Instantiate an uninitialized relocation object.
	 * <p>
	 * NOTE: This method is intended for use by the various factory methods which should generally
	 * be used when building-up a relocation table (see {@link #createElfRelocation(BinaryReader, ElfHeader, int, boolean)}
	 * and {@link #createElfRelocation(ElfHeader, int, boolean, long, long, long)}).
	 */
	public ElfRelocation() {
	}

	/**
	 * Initialize ELF relocation entry using data from the binary reader's current position. 
	 * @param reader binary reader positioned to the relocation entry data.  If null, 
	 * a representative instance will be generated with all fields set to 0.
	 * @param elfHeader ELF header
	 * @param relocationTableIndex index of relocation within relocation table
	 * @param withAddend true if if RELA entry with addend, else false
	 * @throws IOException if an IO or parse error occurs
	 */
	protected void initElfRelocation(BinaryReader reader, ElfHeader elfHeader,
			int relocationTableIndex, boolean withAddend) throws IOException {
		this.is32bit = elfHeader.is32Bit();
		this.relocationIndex = relocationTableIndex;
		this.hasAddend = withAddend;
		if (reader != null) {
			readEntryData(reader);
		}
	}

	/**
	 * Initialize ELF relocation entry using data provided via the parameters.
	 * @param elfHeader ELF header
	 * @param relocationTableIndex index of relocation within relocation table
	 * @param withAddend true if if RELA entry with addend, else false
	 * @param offset The offset for the entry (r_offset)
	 * @param info The info value for the entry (r_info)
	 * @param addend The addend for the entry (r_addend)
	 * @throws IOException if an IO or parse error occurs
	 */
	protected void initElfRelocation(ElfHeader elfHeader, int relocationTableIndex,
			boolean withAddend, long offset, long info, long addend) throws IOException {
		this.is32bit = elfHeader.is32Bit();
		this.relocationIndex = relocationTableIndex;
		this.hasAddend = withAddend;

		if (is32bit) {
			this.r_offset = Integer.toUnsignedLong((int) offset);
			this.r_info = Integer.toUnsignedLong((int) info);
			if (hasAddend) {
				this.r_addend = Integer.toUnsignedLong((int) addend);
			}
		}
		else {
			this.r_offset = offset;
			this.r_info = info;
			if (hasAddend) {
				this.r_addend = addend;
			}
		}
	}

	private void readEntryData(BinaryReader reader) throws IOException {
		if (is32bit) {
			this.r_offset = Integer.toUnsignedLong(reader.readNextInt());
			this.r_info = Integer.toUnsignedLong(reader.readNextInt());
			if (hasAddend) {
				r_addend = Integer.toUnsignedLong(reader.readNextInt());
			}
		}
		else {
			this.r_offset = reader.readNextLong();
			this.r_info = reader.readNextLong();
			if (hasAddend) {
				r_addend = reader.readNextLong();
			}
		}
	}

	/**
	 * @return index of relocation within its corresponding relocation table
	 */
	public int getRelocationIndex() {
		return relocationIndex;
	}

	/**
	 * @return true if processing a 32-bit header, else 64-bit
	 */
	protected boolean is32Bit() {
		return is32bit;
	}

	/**
	 * This member gives the location at which to apply the relocation action. 
	 * 
	 * For a relocatable file, the value is the byte offset from the 
	 * beginning of the section to the storage unit affected by the relocation. 
	 * 
	 * For an executable file or a shared object, the value is the virtual address of
	 * the storage unit affected by the relocation.
	 * 
	 * @return the location at which to apply the relocation
	 */
	public long getOffset() {
		return r_offset;
	}

	/**
	 * Returns the symbol index where the relocation must be made.
	 * A value of 0 is generally returned when no symbol is relavent
	 * to the relocation.
	 * @return the symbol index
	 */
	public int getSymbolIndex() {
		return (int) (is32bit ? (r_info >> 8) : (r_info >> 32));
	}

	/**
	 * The type of relocation to apply.
	 * NOTE 1: Relocation types are processor-specific (see {@link ElfRelocationHandler}).
	 * NOTE 2: A type of 0 is returned by default for RELR relocations and must be updated 
	 * during relocation processing (see {@link #setType(long)}).  The appropriate RELR 
	 * relocation type can be obtained from the appropriate 
	 * {@link ElfRelocationHandler#getRelrRelocationType()} or 
	 * {@link ElfRelocationContext#getRelrRelocationType()} if available.
	 * @return type of relocation to apply
	 */
	public int getType() {
		return (int) (is32bit ? (r_info & BYTE_MASK) : (r_info & INT_MASK));
	}

	/**
	 * Set the relocation type associated with this relocation.
	 * Updating the relocation type is required for RELR relocations.
	 * @param type relocation type to be applied
	 */
	public void setType(long type) {
		long mask = is32bit ? BYTE_MASK : INT_MASK;
		r_info = (r_info & ~mask) + (type & mask);
	}
	
	/**
	 * Returns the r_info relocation entry field value
	 * @return r_info value
	 */
	public long getRelocationInfo() {
		return r_info;
	}

	/**
	 * This member specifies a constant addend used to compute 
	 * the value to be stored into the relocatable field.  This
	 * value will be 0 for REL entries which do not supply an addend.
	 * @return a constant addend
	 */
	public long getAddend() {
		return r_addend;
	}

	/**
	 * Returns true if this is a RELA entry with addend
	 * @return true if this is a RELA entry with addend
	 */
	public boolean hasAddend() {
		return hasAddend;
	}

	@Override
	public DataType toDataType() {
		String dtName = is32bit ? "Elf32_Rel" : "Elf64_Rel";
		if (hasAddend) {
			dtName += "a";
		}
		Structure struct = new StructureDataType(new CategoryPath("/ELF"), dtName, 0);
		DataType fieldDt = is32bit ? DWORD : QWORD;
		struct.add(fieldDt, "r_offset", R_OFFSET_COMMENT);
		struct.add(fieldDt, "r_info", R_INFO_COMMENT);
		if (hasAddend) {
			struct.add(fieldDt, "r_addend", R_ADDEND_COMMENT);
		}
		return struct;
	}

	/**
	 * Get the standard relocation size when one has notbeen specified
	 * @param is64bit true if ELF 64-bit 
	 * @param hasAddend true if relocation has addend
	 * @return size of relocation entry
	 */
	public static int getStandardRelocationEntrySize(boolean is64bit, boolean hasAddend) {
		if (is64bit) {
			return hasAddend ? 24 : 16;
		}
		return hasAddend ? 12 : 8;
	}

	@Override
	public String toString() {
		String str = "Offset: 0x" + Long.toHexString(getOffset()) + " - Type: 0x" +
			Long.toHexString(getType()) + " - Symbol: 0x" + Long.toHexString(getSymbolIndex());
		if (hasAddend) {
			str += " - Addend: 0x" + Long.toHexString(getAddend());
		}
		return str;
	}

	protected int sizeof() {
		if (hasAddend) {
			return is32bit ? 12 : 24;
		}
		return is32bit ? 8 : 16;
	}

}
