// https://www.learncpp.com/cpp-tutorial/introduction-to-standard-library-algorithms

#include <algorithm>
#include <array>
#include <functional>
#include <iostream>

bool greater(int a, int b) {
	// Order @a before @b if @a is greater than @b
	return (a > b);
}

int main() {
	std::array arr { 13, 90, 99, 5, 40, 80 };
	
	// Pass greater to std::sort
	std::sort(arr.begin(), arr.end(), greater);
	// std::sort(arr.begin(), arr.end(), std::greater{});  // use the standard library greater comparison
	// Before C++17, we had to specify the element type when we create std::greater
	// std::sort(arr.begin(), arr.end(), std::greater<int>{});

	for (int i : arr) {
		std::cout << i << ' ';
	}

	std::cout << '\n';

	return 0;
}