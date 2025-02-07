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
package ghidra.trace.util;

import java.util.Iterator;
import java.util.function.Predicate;
import java.util.stream.Stream;
import java.util.stream.StreamSupport;

import org.apache.commons.collections4.IteratorUtils;

import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;

public class WrappingFunctionIterator implements FunctionIterator {
	private Iterator<? extends Function> it;

	public WrappingFunctionIterator(Iterator<? extends Function> it) {
		this.it = it;
	}

	public <T extends Function> WrappingFunctionIterator(Iterator<T> it,
			Predicate<? super T> filter) {
		Iterable<T> iterable = () -> it;
		Stream<T> filterStream = StreamSupport.stream(iterable.spliterator(), false);
		this.it = filterStream.filter(filter).iterator();
	}

	@Override
	public boolean hasNext() {
		return it.hasNext();
	}

	@Override
	public Function next() {
		return it.next();
	}

	@Override
	public Iterator<Function> iterator() {
		return this;
	}
}
