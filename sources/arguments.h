/*
 * arguments.cpp
 *
 *  Created on: 19.04.2015
 *      Author: leo
 */

#include "../headers/arguments.h"
#include <vector>
#include <string>
#include <iostream>
#include "../liberror/liberror.h"
#include <sstream>
#include <typeinfo>

using std::vector;
using std::string;
using std::cout;
using err::error;
using std::stringstream;
using std::type_info;



vector<string> convert_arguments(int argc, char* argv[]) {
	vector<string> return_vector;
	for (int i = 0; i <= argc-1; i++) {
		return_vector.push_back(argv[i]);
	}
	return return_vector;
}

template<typename T>
bool argument_is_type(string argument) {
	stringstream converter;
	T type_variable;
	converter << argument;
	converter >> type_variable;
	if (converter.fail()) {
		return false;
	}
	else {
		return true;
	}
}

template<typename T>
arguments<T> parse_arguments(int argc, char* argv[]) {
	vector<string> args = convert_arguments(argc, argv);
	arguments<T> return_values;
	int i = 1;
	return_values.type = typeid(T).name();
	while (i <= args.size()-1) {
		if (args.at(i) == "-t" || args.at(i) == "--type") {
			++i;
			//already parsed and used in T
		}
		else if (args.at(i) == "-d" || args.at(i) == "--display") {
			return_values.display_information = true;
		}
		else if (args.at(i) == "-O" || args.at(i) == "--output-information") {
			return_values.output_information = true;
			return_values.information_path = args.at(i+1);
			++i;
		}
		else if (args.at(i) == "-i" || args.at(i) == "--input") {
			if (return_values.random_input == true) {
				cout << "Combination of random input and input file not possible, choose one method\n";
				throw error(2, "Incorrect arguments");
				break;
			}
			else {
				return_values.input_data = true;
				return_values.input_path = args.at(i+1);
				++i;
			}
		}
		else if (args.at(i) == "-o" || args.at(i) == "--output") {
			return_values.output_data = true;
			return_values.output_path = args.at(i+1);
			++i;
		}
		else if (args.at(i) == "-r" || args.at(i) == "--random-input") {
			if (return_values.input_data == true) {
				cout << "Combination of random input and input file not possible, choose one method\n";
				throw error(2, "Incorrect arguments");
			}
			else {
				return_values.random_input = true;
				if (argument_is_type<long long int>(args.at(i+1))) {
					stringstream converter(args.at(i+1));
					converter >> return_values.random_input_length;
					++i;
				}
				if (argument_is_type<T>(args.at(i+1))) {
					stringstream converter(args.at(i+1));
					converter >> return_values.random_input_start;
					++i;
				}
				if (argument_is_type<T>(args.at(i+1))) {
					stringstream converter(args.at(i+1));
					converter >> return_values.random_input_end;
					++i;
				}

				if (return_values.random_input_end < return_values.random_input_start) {
					return_values.random_input_end = return_values.random_input_start +1;
				}

			}
		}
		else {
			throw error(3, "Unknown argument '" + args.at(i) + "'");
			break;
		}
		++i;
	}

	if (return_values.input_data == false && return_values.random_input == false) {
		cout << "Neither random input nor input file defined, choose one method\n";
		throw error(2, "Incorrect arguments");
	}

	return return_values;
}

string get_input_type(int argc, char* argv[]) {
	vector<string> args = convert_arguments(argc, argv);
	for (int i = 0; i <= args.size()-1; i++) {
		if ((args.at(i) == "-t" || args.at(i) == "--type") && i != args.size()-1) {
			if (args.at(i+1)=="string" || args.at(i+1)=="char") {
				return typeid(string).name();
			}
			else if (args.at(i+1)=="int" || args.at(i+1)=="short") {
				return typeid(int).name();
			}
			else if (args.at(i+1)=="long") {
				return typeid(long).name();
			}
			else if (args.at(i+1)=="double" || args.at(i+1)=="float") {
				return typeid(double).name();
			}
			else {
				throw error(5, "Unknown type '" + args.at(i+1) + "'");
				break;
			}
			break;
		}
		else if (i == args.size()-1) {
			throw error(4, "No given type");
		}
	}
}
