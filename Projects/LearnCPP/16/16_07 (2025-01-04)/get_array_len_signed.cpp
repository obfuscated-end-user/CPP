// https://www.learncpp.com/cpp-tutorial/arrays-loops-and-sign-challenge-solutions

#include <iostream>
#include <vector>

using Index = std::ptrdiff_t;

int main() {
	std::vector arr { 9, 7, 5, 3, 1 };

	for (auto index { static_cast<Index>(arr.size()) - 1 }; index >= 0; --index)
		std::cout << arr[static_cast<std::size_t>(index)] << ' ';

	std::cout << '\n';

	auto length { static_cast<Index>(arr.size()) };
	for (auto index { length - 1 }; index >= 0; --index)
		std::cout << arr[static_cast<std::size_t>(index)] << ' ';

	std::cout << '\n';

	for (auto index { std::ssize(arr) - 1 }; index >= 0; --index)	// std::ssize introduced in C++20
		std::cout << arr[static_cast<std::size_t>(index)] << ' ';

	return 0;
}