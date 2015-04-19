/*
 * arguments.h
 *
 *  Created on: 19.04.2015
 *      Author: leo
 */

#ifndef HEADERS_ARGUMENTS_H_
#define HEADERS_ARGUMENTS_H_

#include <string>
#include <vector>

using std::string;
using std::vector;

template<typename T>
struct arguments {
	string type;
	bool display_information = false;
	bool output_information = false;
	string information_path;
	bool input_data = false;
	string input_path;
	bool output_data = false;
	string output_path;
	bool random_input = false;
	long long int random_input_length = 1;
	T random_input_start = 0;
	T random_input_end = 1;
};

#include "../sources/arguments.h"


#endif /* HEADERS_ARGUMENTS_H_ */
