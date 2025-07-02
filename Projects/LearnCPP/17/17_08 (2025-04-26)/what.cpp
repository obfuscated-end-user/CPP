// https://www.learncpp.com/cpp-tutorial/c-style-array-decay

#include <iostream>

void printElementZero(int arr[1000]) {	// doesn't make a copy
	std::cout << arr[0];				// print the value of the first element
}

int main() {
	int x[7] { 5 };			// define an array with 7 elements
	printElementZero(x);	// somehow works!

	return 0;
}