// https://www.learncpp.com/cpp-tutorial/pointer-arithmetic-and-array-indexing

/*
Question #1

Why does the following code work?
*/

#include <iostream>

int main() {
	int arr[]{ 1, 2, 3 };

	std::cout << 2[arr] << '\n';

	return 0;
}

/*
The subscript operator ([]) is identical to an addition and an indirection, the operands can be swapped.
arr[2] is the same as *(arr + 2), which in turn also the same as *(2 + arr) and therefore 2[arr]
*/