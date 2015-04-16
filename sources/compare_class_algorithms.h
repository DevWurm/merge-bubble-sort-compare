/*
	 * License

	 * Copyright 2015 DevWurm

	 * This file is part of merge_sort_bubble_sort_compare.

	 *  merge_sort_bubble_sort_compare is free software: you can redistribute it and/or modify
	    it under the terms of the GNU General Public License as published by
	    the Free Software Foundation, either version 3 of the License, or
	    (at your option) any later version.

	    merge_sort_bubble_sort_compare is distributed in the hope that it will be useful,
	    but WITHOUT ANY WARRANTY; without even the implied warranty of
	    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	    GNU General Public License for more details.

	    You should have received a copy of the GNU General Public License
	    along with merge_sort_bubble_sort_compare.  If not, see <http://www.gnu.org/licenses/>.

	    Diese Datei ist Teil von merge_sort_bubble_sort_compare.

	    merge_sort_bubble_sort_compare ist Freie Software: Sie können es unter den Bedingungen
	    der GNU General Public License, wie von der Free Software Foundation,
	    Version 3 der Lizenz oder (nach Ihrer Wahl) jeder späteren
	    veröffentlichten Version, weiterverbreiten und/oder modifizieren.

	    merge_sort_bubble_sort_compare wird in der Hoffnung, dass es nützlich sein wird, aber
	    OHNE JEDE GEWÄHRLEISTUNG, bereitgestellt; sogar ohne die implizite
	    Gewährleistung der MARKTFÄHIGKEIT oder EIGNUNG FÜR EINEN BESTIMMTEN ZWECK.
	    Siehe die GNU General Public License für weitere Details.

	    Sie sollten eine Kopie der GNU General Public License zusammen mit diesem
	    Programm erhalten haben. Wenn nicht, siehe <http://www.gnu.org/licenses/>.
*/

#include "../headers/compare_class.h"
#include "deque_functions.h"
#include <deque>

using std::deque;


namespace compare {

template<typename T>
deque<T> merge_sort_merge(deque<T>& list1, deque<T>& list2) {
	if (list1.size()==1 && list2.size()==0) {
		return list1;
	}
	else {
		deque<T> listret;
		while (list1.size() > 0 && list2.size() >0) {
			if (list1.at(0)<list2.at(0)) {
				restack(list1, listret, 1);
			}
			else {
				restack(list2, listret, 1);
			}
		}
		if (list1.size()>0) {
			restack(list1, listret, list1.size());
		}
		else if (list2.size()>0) {
			restack(list2, listret, list2.size());
		}
		return listret;
	}

}

template<typename T>
void compare_class<T>::algorithm_1(const deque<T>& input, deque<T>& result) { // merge sort
	int input_size = input.size();
	result = input;
	for (int list_width = 1; list_width < input_size; list_width *= 2) {
		deque<T> buffer;
		restack(result, buffer, result.size());
		while (buffer.size() > 0) {
			deque<T> list1;
			deque<T> list2;
			if (buffer.size() >= list_width) {
				restack(buffer, list1, list_width);
			}
			else {
				restack(buffer, list1, buffer.size());
			}
			if (buffer.size() >= list_width) {
				restack(buffer, list2, list_width);
			}
			else {
				restack(buffer, list2, buffer.size());
			}
			deque<T> return_buffer = merge_sort_merge(list1, list2);
			restack(return_buffer, result, return_buffer.size());
		}

	}
}

template<typename T>
void switch_positions(deque<T>& input, int position_1, int position_2) {
	T buffer = input.at(position_1);
	input.at(position_1) = input.at (position_2);
	input.at(position_2) = buffer;
}

template<typename T>
void compare_class<T>::algorithm_2(const deque<T>& input, deque<T>& result) { //bubble sort
	result = input;
	for (int i = result.size(); i > 1; i--) {
		for (j = 0; j < i-1; j++) {
			if (result.at(j) > result.at(j+1)) {
				switch_positions(result, j, j+1);
			}
		}
	}

}

}
