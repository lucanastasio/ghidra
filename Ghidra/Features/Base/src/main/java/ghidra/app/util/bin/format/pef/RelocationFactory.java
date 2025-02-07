/* ###
 * IP: GHIDRA
 * REVIEWED: YES
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
import ghidra.util.Msg;

import java.lang.reflect.Constructor;

public class RelocationFactory {

	private static Class<?> [] relocationClasses = new Class<?>[] {
		RelocByIndexGroup.class,
		RelocBySectDWithSkip.class,
		RelocIncrPosition.class,
		RelocLgByImport.class,
		RelocLgRepeat.class,
		RelocLgSetOrBySection.class,
		RelocSetPosition.class,
		RelocSmRepeat.class,
		RelocUndefinedOpcode.class,
		RelocValueGroup.class,
	};

	private static ParseState parseState = new ParseState();

	public static Relocation getRelocation(BinaryReader reader) {
		long index = reader.getPointerIndex();
		for (Class<?> relocationClass : relocationClasses) {
			try {
				Constructor<?> constructor = relocationClass.getDeclaredConstructor(new Class[]{BinaryReader.class, ParseState.class});
				Relocation relocation = (Relocation)constructor.newInstance(new Object[]{reader, parseState});
				if (relocation.isMatch()) {
					return relocation;
				}
			}
			catch (Exception e) {
			    Msg.error(RelocationFactory.class, "Unexpected Exception: " + e.getMessage(), e);
			}
			reader.setPointerIndex(index);
		}
		throw new IllegalStateException();
	}
}
