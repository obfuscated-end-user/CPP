// https://www.learncpp.com/cpp-tutorial/introduction-to-c-style-arrays

#include <iostream>

int main() {
	const int prime[] { 2, 3, 5, 7, 11 };	// the compiler will deduce prime to have length 5
	std::cout << sizeof(prime);				// prints 20 (assuming 4 byte ints)

	return 0;
}