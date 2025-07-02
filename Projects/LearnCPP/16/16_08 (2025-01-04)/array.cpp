// https://www.learncpp.com/cpp-tutorial/range-based-for-loops-for-each

#include <array>
#include <iostream>

int main() {
	std::array fibonacci { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };	// note use of std::array here

	for (auto number : fibonacci)
		std::cout << number << ' ';

	std::cout << '\n';

	return 0;
}