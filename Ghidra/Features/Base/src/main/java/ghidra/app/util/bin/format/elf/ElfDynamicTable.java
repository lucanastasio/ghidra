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
import java.util.*;

import ghidra.app.util.bin.BinaryReader;
import ghidra.app.util.bin.StructConverter;
import ghidra.program.model.data.*;
import ghidra.util.exception.DuplicateNameException;
import ghidra.util.exception.NotFoundException;

/**
 * If an object file participates in dynamic linking, its program header table 
 * will have an element of type PT_DYNAMIC. This "segment" contains the ".dynamic" section. 
 * A special symbol, _DYNAMIC, labels the section, which contains an array of the 
 * Elf32_Dyn or Elf64_Dyn structures.
 * <p>
 * All address entries contained within this table should adjusted for pre-linking 
 * using {@link ElfHeader#adjustAddressForPrelink(long)}.  If a pre-link adjustment is not applicable, 
 * this adjustment will have no affect.
 */
public class ElfDynamicTable implements StructConverter {

	private List<ElfDynamic> dynamics = new ArrayList<ElfDynamic>();

	private ElfHeader header;
	private ElfFileSection fileSection;

	public ElfDynamicTable(ElfHeader header, ElfFileSection fileSection) throws IOException {
		this.header = header;
		this.fileSection = fileSection;

		BinaryReader reader = fileSection.getReader();
		// Collect set of all _DYNAMIC array tags specified in .dynamic section
		while (true) {
			ElfDynamic dyn = new ElfDynamic(reader, header);
			dynamics.add(dyn);
			if (dyn.getTag() == ElfDynamicType.DT_NULL.value) {
				break;
			}
		}
	}

	/**
	 * Adds the new dynamic at the specified index.
	 * @param dyn    the new dynamic
	 * @param index  the new index
	 */
	public void addDynamic(ElfDynamic dyn, int index) {
		dynamics.add(index, dyn);
	}

	/**
	 * Returns an array of the dynamics defined this dynamic header.
	 * @return an array of the dynamics defined this dynamic header
	 */
	public ElfDynamic[] getDynamics() {
		ElfDynamic[] array = new ElfDynamic[dynamics.size()];
		dynamics.toArray(array);
		return array;
	}

	/**
	 * Returns an array of the dynamics defined this dynamic header
	 * with the specified type.
	 * @param type the desired dynamic type, e.g., DT_NEEDED
	 * @return an array of the dynamics defined this dynamic header
	 */
	public ElfDynamic[] getDynamics(long type) {
		List<ElfDynamic> list = new ArrayList<ElfDynamic>();
		for (int i = 0; i < dynamics.size(); i++) {
			ElfDynamic dyn = dynamics.get(i);
			if (dyn.getTag() == type) {
				list.add(dyn);
			}
		}
		ElfDynamic[] arr = new ElfDynamic[list.size()];
		list.toArray(arr);
		return arr;
	}

	/**
	 * Returns an array of the dynamics defined this dynamic header
	 * with the specified (enum) type.
	 * @param type the desired dynamic type, e.g., DT_NEEDED
	 * @return an array of the dynamics defined this dynamic header
	 */
	public ElfDynamic[] getDynamics(ElfDynamicType type) {
		return getDynamics(type.value);
	}

	/**
	 * Returns the value of the specified dynamic type.
	 * @param type the dynamic type
	 * @return the dynamic value
	 * @throws NotFoundException if requested value type not found
	 */
	public long getDynamicValue(long type) throws NotFoundException {
		for (int i = 0; i < dynamics.size(); i++) {
			ElfDynamic dyn = dynamics.get(i);
			if (dyn.getTag() == type) {
				return dyn.getValue();
			}
		}
		throw new NotFoundException("Dynamic table entry not found: 0x" + Long.toHexString(type));
	}

	/**
	 * Returns true if the specified dynamic (enum) type has a value.
	 * @param type the dynamic (enum) type
	 * @return true if dynamic value exists
	 */
	public boolean containsDynamicValue(ElfDynamicType type) {
		return containsDynamicValue(type.value);
	}

	/**
	 * Returns true if the specified dynamic type has a value.
	 * @param type the dynamic type
	 * @return true if dynamic value exists
	 */
	public boolean containsDynamicValue(long type) {
		for (int i = 0; i < dynamics.size(); i++) {
			ElfDynamic dyn = dynamics.get(i);
			if (dyn.getTag() == type) {
				return true;
			}
		}
		return false;
	}

	/**
	 * Returns the value of the specified dynamic (enum) type.
	 * @param type the dynamic (enum) type
	 * @return the dynamic value
	 * @throws NotFoundException if requested value type not found
	 */
	public long getDynamicValue(ElfDynamicType type) throws NotFoundException {
		return getDynamicValue(type.value);
	}

	public ElfFileSection getFileSection() {
		return fileSection;
	}

	@Override
	public DataType toDataType() throws DuplicateNameException, IOException {

		String typeSuffix = header.getTypeSuffix();
		boolean is32bit = header.is32Bit();
		String name = is32bit ? "Elf32_Dyn" : "Elf64_Dyn";
		if (typeSuffix != null) {
			name = name + typeSuffix;
		}

		Structure structure = new StructureDataType(new CategoryPath("/ELF"), name, 0);
		structure.add(getTagDataType(), "d_tag", null);
		if (is32bit) {
			structure.add(DWORD, "d_val", null);
		}
		else {
			structure.add(QWORD, "d_val", null);
		}
		return new ArrayDataType(structure, dynamics.size(), structure.getLength());
	}

	private DataType getTagDataType() {

		boolean is32bit = header.is32Bit();
		int size = is32bit ? 4 : 8;

		HashMap<Integer, ElfDynamicType> dynamicTypeMap = header.getDynamicTypeMap();
		if (dynamicTypeMap == null) {
			return is32bit ? DWordDataType.dataType : QWordDataType.dataType;
		}

		String name = is32bit ? "Elf32_DynTag" : "Elf64_DynTag";

		String typeSuffix = header.getTypeSuffix();
		if (typeSuffix != null) {
			name = name + typeSuffix;
		}

		EnumDataType dynamicTagEnum = new EnumDataType(new CategoryPath("/ELF"), name, size);
		for (ElfDynamicType type : dynamicTypeMap.values()) {
			dynamicTagEnum.add(type.name, type.value);
		}
		return dynamicTagEnum;
	}

	public long getFileSize() {
		return dynamics.size() * getEntrySize();
	}

	public long getEntrySize() {
		return header.is32Bit() ? 8 : 16;
	}

}
