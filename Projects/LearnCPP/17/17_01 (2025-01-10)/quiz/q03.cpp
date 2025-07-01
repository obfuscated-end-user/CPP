// https://www.learncpp.com/cpp-tutorial/introduction-to-stdarray

/*
Initialize a std::array with the following values: ‘h’, ‘e’, ‘l’, ‘l’, ‘o’. Print the value of the element with index 1.
*/

#include <array>
#include <iostream>

int main() {
	constexpr std::array arr { 'h', 'e', 'l', 'l', 'o' };
	std::cout << arr[1] << '\n';

	return 0;
}