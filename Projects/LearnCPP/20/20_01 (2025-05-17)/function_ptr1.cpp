// https://www.learncpp.com/cpp-tutorial/function-pointers

#include <iostream>

int foo() {
	return 5;
}

int main() {
	std::cout << foo << '\n';	// we meant to call foo(), but instead we're printing foo itself!
	std::cout << reinterpret_cast<void*>(foo) << '\n';	// Tell C++ to interpret function foo as a void pointer (implementation-defined behavior)

	return 0;
}