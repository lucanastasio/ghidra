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
package ghidra.app.util.bin.format.pef;

import ghidra.app.util.bin.BinaryReader;
import ghidra.app.util.importer.MessageLog;
import ghidra.program.model.listing.Program;
import ghidra.util.task.TaskMonitor;

import java.io.IOException;

/**
 * See Apple's -- PEFBinaryFormat.h
 */
public class RelocLgRepeat extends Relocation {
	private int chunkCount;
	private int repeatCount;
	private BinaryReader reader;
	private ParseState parseState;

	RelocLgRepeat(BinaryReader reader, ParseState parseState) throws IOException {
		int value = reader.readNextShort() & 0xffff;

		opcode       =  (value & 0xfc00) >> 10;
		chunkCount   =  (value & 0x03c0) >>  6;
		repeatCount  =  (value & 0x003f) << 16;
		repeatCount |=  reader.readNextShort() & 0xffff;

		this.reader = reader;
		this.parseState = parseState;
	}

	@Override
	public boolean isMatch() {
		if (opcode != 0x2c)
			return false;

		parseState.incrementLoopCount(reader.getPointerIndex() - 4);
		if (parseState.getLoopCount() == repeatCount) {
			/* done looping */
			parseState.clearLoopCount();
		} else {
			/* go back two chunks for this command plus the number of chunks specified */
			reader.setPointerIndex(reader.getPointerIndex() - 4 - (2 * (chunkCount + 1)));
		}

		return true;
	}

	@Override
	public int getSizeInBytes() {
		return 4;
	}

	public int getChunkCount() {
		return chunkCount + 1;
	}

	public int getRepeatCount() {
		return repeatCount;
	}

	@Override
	public void apply(ImportStateCache importState, RelocationState relocState, 
			ContainerHeader header, Program program, MessageLog log, TaskMonitor monitor) {
		/* nothing to do */
	}
}
