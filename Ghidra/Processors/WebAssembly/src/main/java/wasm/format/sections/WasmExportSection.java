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
package wasm.format.sections;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.EnumMap;
import java.util.List;
import java.util.Map;

import ghidra.app.util.bin.BinaryReader;
import ghidra.app.util.bin.LEB128Info;
import ghidra.util.exception.DuplicateNameException;
import wasm.format.StructureBuilder;
import wasm.format.WasmEnums.WasmExternalKind;
import wasm.format.sections.structures.WasmExportEntry;

public class WasmExportSection extends WasmSection {

	private LEB128Info count;
	private List<WasmExportEntry> exportList = new ArrayList<>();
	private Map<WasmExternalKind, List<WasmExportEntry>> exports = new EnumMap<>(WasmExternalKind.class);

	public WasmExportSection(BinaryReader reader) throws IOException {
		super(reader);
		count = reader.readNext(LEB128Info::unsigned);
		for (int i = 0; i < count.asLong(); ++i) {
			WasmExportEntry entry = new WasmExportEntry(reader);
			WasmExternalKind kind = entry.getKind();
			if (!exports.containsKey(kind)) {
				exports.put(kind, new ArrayList<WasmExportEntry>());
			}
			exports.get(kind).add(entry);
			exportList.add(entry);
		}
	}

	public List<WasmExportEntry> getExports(WasmExternalKind kind) {
		return exports.getOrDefault(kind, Collections.emptyList());
	}

	public WasmExportEntry findEntry(WasmExternalKind kind, int id) {
		for (WasmExportEntry entry : getExports(kind)) {
			if (entry.getIndex() == id) {
				return entry;
			}
		}
		return null;
	}

	@Override
	protected void addToStructure(StructureBuilder builder) throws DuplicateNameException, IOException {
		builder.addUnsignedLeb128(count, "count");
		for (int i = 0; i < exportList.size(); i++) {
			builder.add(exportList.get(i), "export_" + i);
		}
	}

	@Override
	public String getName() {
		return ".export";
	}
}
