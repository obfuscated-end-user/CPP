// https://www.learncpp.com/cpp-tutorial/introduction-to-lambdas-anonymous-functions

#include <algorithm>
#include <array>
#include <functional>	// for std::greater
#include <iostream>

bool greater(int a, int b) {
	// Order @a before @b if @a is greater than @b.
	return a > b;
}

int main() {
	std::array arr { 13, 90, 99, 5, 40, 80 };

	// Pass greater to std::sort
	std::sort(arr.begin(), arr.end(), greater);

	for (int i : arr) {
		std::cout << i << ' ';
	}

	std::cout << '\n';

	// Pass std::greater to std::sort
	std::sort(arr.begin(), arr.end(), std::greater{});  // note: need curly braces to instantiate object

	for (int i : arr) {
		std::cout << i << ' ';
	}

	std::cout << '\n';

	return 0;
}