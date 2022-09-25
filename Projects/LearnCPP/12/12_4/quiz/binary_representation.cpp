// https://www.learncpp.com/cpp-tutorial/recursion/

/*
3a) This one is slightly trickier. Write a program that asks the user to enter a positive integer, and then uses a recursive function to print out the binary representation for that number. Use method 1 from lesson O.4 -- Converting between binary and decimal.

Hint: Using method 1, we want to print the bits from the “bottom up”, which means in reverse order. This means your print statement should be after the recursive call.
*/

#include <iostream>

void printBinary(int x) {
	if (x == 0)
		return;

	printBinary(x / 2);

	std::cout << x % 2; // same as the odd even shit
}

int main() {
    int x;
	std::cout << "Enter a positive integer: ";
	std::cin >> x;

    printBinary(x);

    /* int num = 9;
    int bin = 2 / 2;

    std::cout << bin; */

    return 0;
}