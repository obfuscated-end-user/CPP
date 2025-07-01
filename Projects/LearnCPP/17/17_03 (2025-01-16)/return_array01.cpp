// https://www.learncpp.com/cpp-tutorial/passing-and-returning-stdarray

#include <array>
#include <iostream>
#include <limits>

// return by value
template <typename T, std::size_t N>
std::array<T, N> inputArray() {	// return by value
	std::array<T, N> arr {};
	std::size_t index { 0 };

	while (index < N) {
		std::cout << "Enter value #" << index << ": ";
		std::cin >> arr[index];

		if (!std::cin) {	// handle bad input
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		++index;
	}

	return arr;
}

int main() {
	std::array<int, 5> arr { inputArray<int, 5>() };

	std::cout << "The value of element 2 is " << arr[2] << '\n';

	return 0;
}