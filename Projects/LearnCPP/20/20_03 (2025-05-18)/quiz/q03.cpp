// https://www.learncpp.com/cpp-tutorial/recursion

/*
3a) This one is slightly trickier. Write a program that asks the user to enter a positive integer, and then uses a recursive function to print out the binary representation for that number. Use method 1 from lesson O.4 -- Converting integers between binary and decimal representation.

Hint: Using method 1, we want to print the bits in reverse order. This means your print statement should be after the recursive call.

3b) Extra credit: Update your code from 3a to handle the case where the user may enter 0 or a negative number.

Here’s a sample output (assuming 32-bit integers):

```
Enter an integer: -15
11111111111111111111111111110001
```

Hint: Your printBinary() function doesn’t actually need to handle negative numbers. If you pass it a positive value with the same binary representation as the negative number, it will produce the correct output.

Hint: Converting between signed and unsigned does not change the binary representation, just the way the value is interpreted. For example, signed integer -15 has binary representation 11111111111111111111111111110001, the same as unsigned integer 4294967281.

Hint: A signed value can be positive or negative, but an unsigned value is always positive…
*/

// h/t to reader Donlod for this solution
#include <iostream>

void printBinary(unsigned int n) {
	if (n > 1)  // we only recurse if n > 1, so this is our termination case for n == 0
		printBinary(n / 2);

	std::cout << n % 2;
}

int main() {
	int x {};
	std::cout << "Enter an integer: ";
	std::cin >> x;
	printBinary(static_cast<unsigned int>(x));

	return 0;
}

// As the hints note, converting between signed and unsigned does not change the binary representation, just the way the value is interpreted. Therefore, if we capture the user’s input in a signed int, and then convert that to an unsigned int, we will get a value that is always positive but has the same binary representation as the signed value the user entered. That way, our function only has to handle positive numbers.