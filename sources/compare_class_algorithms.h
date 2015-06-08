/*
	 * License

	 * Copyright 2015 DevWurm

	 * This file is part of merge_bubble_sort_compare.

	 *  merge_bubble_sort_compare is free software: you can redistribute it and/or modify
	    it under the terms of the GNU General Public License as published by
	    the Free Software Foundation, either version 3 of the License, or
	    (at your option) any later version.

	    merge_bubble_sort_compare is distributed in the hope that it will be useful,
	    but WITHOUT ANY WARRANTY; without even the implied warranty of
	    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	    GNU General Public License for more details.

	    You should have received a copy of the GNU General Public License
	    along with merge_bubble_sort_compare.  If not, see <http://www.gnu.org/licenses/>.

	    Diese Datei ist Teil von merge_bubble_sort_compare.

	    merge_bubble_sort_compare ist Freie Software: Sie können es unter den Bedingungen
	    der GNU General Public License, wie von der Free Software Foundation,
	    Version 3 der Lizenz oder (nach Ihrer Wahl) jeder späteren
	    veröffentlichten Version, weiterverbreiten und/oder modifizieren.

	    merge_bubble_sort_compare wird in der Hoffnung, dass es nützlich sein wird, aber
	    OHNE JEDE GEWÄHRLEISTUNG, bereitgestellt; sogar ohne die implizite
	    Gewährleistung der MARKTFÄHIGKEIT oder EIGNUNG FÜR EINEN BESTIMMTEN ZWECK.
	    Siehe die GNU General Public License für weitere Details.

	    Sie sollten eine Kopie der GNU General Public License zusammen mit diesem
	    Programm erhalten haben. Wenn nicht, siehe <http://www.gnu.org/licenses/>.
*/

#include <deque>
#include "../headers/compare_class.h"
#include "../headers/deque_functions.h"
#include "../headers/merge_sort_functions.h"

using std::deque;


namespace compare {

template<typename T>
void compare_class<T>::algorithm_1(const deque<T>& input, deque<T>& result) { // merge sort
	int input_size = input.size();
	result = input;

	//repeat the merging algorithm until input is sorted completely
	for (int list_width = 1; list_width < input_size; list_width *= 2) {
		deque<T> buffer;
		restack(result, buffer, result.size());

		//cycle through  the list and take list pairs with the size list_width
		while (buffer.size() > 0) {
			deque<T> list1;
			deque<T> list2;
			if (buffer.size() >= list_width) {
				restack(buffer, list1, list_width); //move list_width elements into list1
			}
			else {
				//if less then list_width elements are remaining, move all remaining elements into list1
				restack(buffer, list1, buffer.size());
			}
			if (buffer.size() >= list_width) {
				restack(buffer, list2, list_width); //move list_width elements into list2
			}
			else {
				//if less then list_width elements are remaining, move all remaining elements into list2
				restack(buffer, list2, buffer.size());
			}
			deque<T> return_buffer = merge_sort_merge(list1, list2); //merge the lists (list2 will always
																	//be the smaller list)
			restack(return_buffer, result, return_buffer.size()); //move the result into result list
		}

	}
}

template<typename T>
void compare_class<T>::algorithm_2(const deque<T>& input, deque<T>& result) { //bubble sort
	result = input;
	for (int i = result.size(); i > 1; i--) {
		for (int j = 0; j < i-1; j++) {
			if (result.at(j) > result.at(j+1)) {
				switch_positions(result, j, j+1);
			}
		}
	}

}

}
