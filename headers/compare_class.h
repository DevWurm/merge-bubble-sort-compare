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

#ifndef HEADERS_COMPARE_CLASS_H_
#define HEADERS_COMPARE_CLASS_H_

#include "../libcompare/libcompare.h"
#include "../libcsv/libcsv.h"
#include <deque>

using std::deque;
using csv::csv_creator;
using csv::csv_parser;

namespace compare {

template<typename T>
class compare_class: public compare_base<deque<T> > {
public:
	template<typename S>
	friend compare_class<S>& operator >>(csv_parser<S>& input, compare_class<S>& target);
	csv_creator<T>& operator >>(csv_creator<T>& target);
	template<typename S>
	friend istream& operator >>(istream& input, compare_class<S>& target);
	template<typename S>
	friend ostream& operator <<(ostream& output, compare_class<S>& source);

	int get_data_length() const;

	void algorithm_1(const deque<T>& input, deque<T>& result);
	void algorithm_2(const deque<T>& input, deque<T>& result);

};

}

#include "../sources/compare_class_algorithms.h"
#include "../sources/compare_class_get.h"
#include "../sources/compare_class_operators.h"
#include "../sources/deque_functions.h"

#endif /* HEADERS_COMPARE_CLASS_H_ */
