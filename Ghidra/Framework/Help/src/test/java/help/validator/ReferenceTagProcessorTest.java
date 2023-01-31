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
package help.validator;

import static org.junit.Assert.assertTrue;

import org.junit.Test;
import java.util.Locale;

import help.AbstractHelpTest;

public class ReferenceTagProcessorTest extends AbstractHelpTest {
	@Test
	public void testIsTagSupported() {
		ReferenceTagProcessor processor = new ReferenceTagProcessor(null, null);

		// The Turkey Test
		Locale defaultLocale = Locale.getDefault();
		Locale.setDefault(new Locale("tr", "TR"));
		assertTrue(processor.isTagSupported("title"));
		assertTrue(processor.isTagSupported("TITLE"));
		assertTrue(!processor.isTagSupported("tıtle"));
		assertTrue(!processor.isTagSupported("TİTLE"));
		Locale.setDefault(defaultLocale);
	}

	@Test
	public void testProcessTag() {
		// Not sure how to test this
	}
}
