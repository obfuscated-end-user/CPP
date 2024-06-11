// https://www.learncpp.com/cpp-tutorial/recursion

/*
3b) Update your code from 3a to handle the case where the user may enter 0 or a negative number.

Here’s a sample output (assuming 32-bit integers):

Enter an integer: -15
11111111111111111111111111110001

Hint: You can turn a negative integer into a positive one by converting it to an unsigned integer. These have identical bit representations (the type is used to determine how to interpret the number into decimal).
*/

#include <iostream>

void printBinary(unsigned int n) {
     // we only recurse if n > 1, so this is our termination case for n == 0
	if (n > 1)
		printBinary(n / 2);

	std::cout << n % 2;
}

int main() {
	int x{};
	std::cout << "Enter an integer: ";
	std::cin >> x;

	printBinary(static_cast<unsigned int>(x));
}