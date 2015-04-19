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
#include <stdexcept>
#include <cmath>
#include "../liberror/liberror.h"
#include "../headers/deque_functions.h"

using std::deque;
using std::out_of_range;
using err::error;

namespace compare {

template<typename T>
void restack(deque<T>& source, deque<T>& target, int n){ //move n elements from the front of source to the end of target
	for (int i = 0; i <= n-1; i++) {
		try {
			target.push_back(source.at(0));
			source.pop_front();
		}
		catch (out_of_range& e) {
			throw(error(1, "Not enough entries in source list"));
		}
	}
}


template<typename T>
void switch_positions(deque<T>& input, int position_1, int position_2) {  //switch the elements position_1 and position_1 in input
	T buffer = input.at(position_1);
	input.at(position_1) = input.at (position_2);
	input.at(position_2) = buffer;
}

}

