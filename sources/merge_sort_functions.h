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
#include "../headers/merge_sort_functions.h"

using std::deque;

namespace compare {

template<typename T>
deque<T> merge_sort_merge(deque<T>& list1, deque<T>& list2) { //list2 will always be the smaller list
	//if list2 is empty use list1 as return list
	if (list1.size() > 0 && list2.size()==0) {
		return list1;
	}
	else {
		deque<T> listret;

		//cycle trough lists and compare the first elements, move the smaller element into result list
		while (list1.size() > 0 && list2.size() >0) {
			if (list1.at(0)<list2.at(0)) {
				restack(list1, listret, 1);
			}
			else {
				restack(list2, listret, 1);
			}
		}
		// if on list is empty, move all remaining elements into result list
		if (list1.size()>0) {
			restack(list1, listret, list1.size());
		}
		else if (list2.size()>0) {
			restack(list2, listret, list2.size());
		}
		return listret;
	}

}

}
