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

/**
 * This class maintains the running state while
 * parsing PEF relocations.
 * <p>
 * <b><code>loopCount</code></b>
 * Holds the number of times the current repeat has been processed.
 * <p>
 * <b><code>lastIndex</code></b>
 * Holds an index in the BinaryReader for the currently-active repeat.
 */
public class ParseState {
	private int loopCount = 0;
	private long lastIndex = -1;

	/**
	 * Increments the loop count by one.
	 * @param index the index in the BinaryReader for the repeat
	 */
	public void incrementLoopCount(long index) {
		if (lastIndex != -1 && lastIndex != index)
			throw new RuntimeException("active repeat is at a different index; nesting repeats is not permitted!");

		++loopCount;
	}

	/**
	 * Clears the loop count.
	 */
	public void clearLoopCount() {
		loopCount = 0;
		lastIndex = -1;
	}

	/**
	 * Returns the loop count.
	 * @return the current loop count
	 */
	public int getLoopCount() {
		return this.loopCount;
	}
}
