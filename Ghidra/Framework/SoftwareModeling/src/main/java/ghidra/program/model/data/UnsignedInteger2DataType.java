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
package ghidra.program.model.data;

import ghidra.util.classfinder.ClassTranslator;

public class UnsignedInteger2DataType extends AbstractIntegerDataType {

	private static final long serialVersionUID = 1L;

	/** A statically defined UnsignedInteger2DataType instance.*/
	public final static UnsignedInteger2DataType dataType = new UnsignedInteger2DataType();

	static {
		ClassTranslator.put("ghidra.program.model.data.ThreeByteDataType",
			UnsignedInteger2DataType.class.getName());
	}

	public UnsignedInteger2DataType() {
		this(null);
	}

	public UnsignedInteger2DataType(DataTypeManager dtm) {
		super("uint2", false, dtm);
	}

	@Override
	public String getDescription() {
		return "Unsigned 2-Byte Integer)";
	}

	@Override
	public int getLength() {
		return 2;
	}

	@Override
	public Integer2DataType getOppositeSignednessDataType() {
		return Integer2DataType.dataType.clone(getDataTypeManager());
	}

	@Override
	public UnsignedInteger2DataType clone(DataTypeManager dtm) {
		if (dtm == getDataTypeManager()) {
			return this;
		}
		return new UnsignedInteger2DataType(dtm);
	}
}
