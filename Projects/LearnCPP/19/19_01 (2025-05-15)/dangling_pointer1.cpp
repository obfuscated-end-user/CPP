// https://www.learncpp.com/cpp-tutorial/dynamic-memory-allocation-with-new-and-delete

#include <iostream>

int main() {
	int* ptr { new int };	// dynamically allocate an integer
	*ptr = 7;				// put a value in that memory location

	delete ptr;				// return the memory to the operating system. ptr is now a dangling pointer.

	std::cout << *ptr;		// Dereferencing a dangling pointer will cause undefined behavior
	delete ptr;				// trying to deallocate the memory again will also lead to undefined behavior.

	return 0;
}