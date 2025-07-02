// https://www.learncpp.com/cpp-tutorial/c-style-array-decay

#include <iostream>

void printArraySize(int arr[]) {
	std::cout << sizeof(arr) << '\n';	// prints 4 (assuming 32-bit addresses)
}

int main() {
	int arr[] { 3, 2, 1 };

	std::cout << sizeof(arr) << '\n';	// prints 12 (assuming 4 byte ints)
	printArraySize(arr);
	// 12 and 8 for me

	return 0;
}