// https://www.learncpp.com/cpp-tutorial/pointer-arithmetic-and-subscripting

#include <iostream>

int main() {
	const int arr[] { 9, 7, 5, 3, 1 };

	const int* ptr { arr };	// a normal pointer holding the address of element 0
	std::cout << ptr[2] << '\n';	// subscript ptr to get element 2, prints 5
	std::cout << *((ptr) + (2));	// subscript ptr to get element 2, prints 5

	// ptr[n] is equivalent to *((ptr) + (n))
	// "add n to ptr and move that many steps relative to type size starting from 0, and dereference whatever is in that location"
	// can you see why is this relevant to the lesson?
	// that's right, it adds... pointers.
	// go f yourself

	return 0;
}