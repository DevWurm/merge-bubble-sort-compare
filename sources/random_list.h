#include <random>
#include <deque>

using std::deque;
using std::random_device;
using std::mt19937;
using std::uniform_real_distribution;

template<typename T>
deque<T> generate_random_list (long long int length, T start, T end) {
	deque<T> return_list;
	random_device seed;
	mt19937 engine (seed());
	uniform_real_distribution<double> values (start, end);
	for (long long int i = 0; i <= length-1; i++) {
		return_list.push_back(values(engine));
	}
}
