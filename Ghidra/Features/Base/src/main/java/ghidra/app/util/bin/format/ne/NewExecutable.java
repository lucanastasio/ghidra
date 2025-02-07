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
package ghidra.app.util.bin.format.ne;

import java.io.IOException;

import ghidra.app.util.bin.BinaryReader;
import ghidra.app.util.bin.ByteProvider;
import ghidra.app.util.bin.format.mz.DOSHeader;
import ghidra.program.model.address.SegmentedAddress;

/**
 * A class to manage loading New Executables (NE).
 * 
 * 
 */
public class NewExecutable {
	private BinaryReader reader;
    private DOSHeader dosHeader;
    private WindowsHeader winHeader;

    /**
	 * Constructs a new instance of an new executable.
	 * @param bp the byte provider
	 * @param baseAddr the image base of the executable
	 * @throws IOException if an I/O error occurs.
	 */
	public NewExecutable(ByteProvider bp, SegmentedAddress baseAddr) throws IOException {
		reader = new BinaryReader(bp, true);
		dosHeader = new DOSHeader(reader);

        if (dosHeader.isDosSignature()) {
            try {
				winHeader = new WindowsHeader(reader, baseAddr, dosHeader.e_lfanew());
            }
            catch (InvalidWindowsHeaderException e) {
            }
        }
    }
    /**
     * Returns the underlying binary reader.
     * @return the underlying binary reader
     */
	public BinaryReader getBinaryReader() {
        return reader;
    }
    /**
     * Returns the DOS header from the new executable.
     * @return the DOS header from the new executable
     */
    public DOSHeader getDOSHeader() {
        return dosHeader;
    }
    /**
     * Returns the Windows header from the new executable.
     * @return the Windows header from the new executable
     */
    public WindowsHeader getWindowsHeader() {
        return winHeader;
    }
}
