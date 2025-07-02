// https://www.learncpp.com/cpp-tutorial/stdvector-and-the-unsigned-length-and-subscript-problem

#include <iostream>
#include <vector>

int main() {
	std::vector prime { 2, 3, 5, 7, 11 };

	int index { 3 };							// non-constexpr signed value
	std::cout << prime.data()[index] << '\n';	// okay: no sign conversion warings

	return 0;
}