#include "../headers/compare_class.h"
#include <fstream>
#include <iostream>
#include <deque>
#include "../headers/arguments.h"
#include "../liberror/liberror.h"
#include "random_list.h"

using compare::compare_class;
using namespace std;

template<typename T>
void perform_sorting(int argc, char* argv[]) {
	arguments<T> user_arguments;
	compare_class<T> compare;
	ofstream output_file;
	ofstream information_file;

	try {
		user_arguments = parse_arguments<T>(argc, argv);
	}
	catch (err::error& e) {
		throw;
	}

	if (user_arguments.output_data) {
		output_file.open(user_arguments.output_path);
		if (output_file.fail()) {
			throw err::error(7, "Output file not found");
		}
	}

	if (user_arguments.output_information) {
		information_file.open(user_arguments.information_path);
		if (information_file.fail()) {
			throw err::error(8, "Information output file not found");
		}
	}

	if (user_arguments.input_data) {
		ifstream input_file (user_arguments.input_path);
		string buffer;
		if (input_file.fail()) {
			throw err::error(6, "Input file not found");
		}
		while (getline(input_file, buffer)) {
			compare = buffer;

			if (user_arguments.display_information) {
				cout << "List length: " << compare.get_data_length() << '\n';
				compare.compare_algorithms_verbose(cout);
			}
			else {
				compare.compare_algorithms();
			}

			if (user_arguments.output_data) {
				output_file << compare << '\n';
			}

			if (user_arguments.output_information) {
				information_file << compare.get_data_length() << ',' << compare.get_operation_time_algorithm_1_string() << ',' << compare.get_operation_time_algorithm_2_string() << '\n';
			}
		}
		input_file.close();
	}
	else {
		deque<T> random_data = generate_random_list<T>(user_arguments.random_input_length, user_arguments.random_input_start, user_arguments.random_input_end);
		compare = random_data;
		if (user_arguments.display_information) {
			cout << "List length: " << compare.get_data_length();
			compare.compare_algorithms_verbose(cout);
		}
		else {
			compare.compare_algorithms();
		}

		if (user_arguments.output_data) {
			output_file << compare;
		}

		if (user_arguments.output_information) {
			information_file << compare.get_data_length() << ',' << compare.get_operation_time_algorithm_1_string() << ',' << compare.get_operation_time_algorithm_2_string();
		}
	}

	if (user_arguments.output_data) {
		output_file.close();
	}

	if (user_arguments.output_information) {
		information_file.close();
	}
}
