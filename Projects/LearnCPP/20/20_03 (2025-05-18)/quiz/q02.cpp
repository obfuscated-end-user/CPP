// https://www.learncpp.com/cpp-tutorial/recursion

/*
Write a recursive function that takes an integer as input and returns the sum of each individual digit in the integer (e.g. 357 = 3 + 5 + 7 = 15). Print the answer for input 93427 (which is 25). Assume the input values are positive.
*/

#include <iostream>

int sumDigits(int x) {
	if (x < 10)
		return x;

	return sumDigits(x / 10) + x % 10;
}

int main() {
	std::cout << sumDigits(93427);

	return 0;
}