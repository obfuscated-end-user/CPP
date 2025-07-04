// https://www.learncpp.com/cpp-tutorial/dynamic-memory-allocation-with-new-and-delete

#include <iostream>

int main() {
	int* ptr { new int {} };	// dynamically allocate an integer
	int* otherPtr { ptr };		// otherPtr is now pointed at the same memory location

	delete ptr;		// return the memory to the operating system. ptr and otherPtr are now dangling pointers.
	ptr = nullptr;	// ptr is now a nullptr

	// however, otherPtr is still a dangling pointer!

	int* value { new (std::nothrow) int {} };	// value will be set to a null pointer if the integer allocation fails

	if (!value) {
		// Do error handling here
		std::cerr << "Could not allocate memory";
	}

	// If ptr isn't already allocated, allocate it
	if (!ptr)
		ptr = new int;

	return 0;
}