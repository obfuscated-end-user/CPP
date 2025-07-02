// https://www.learncpp.com/cpp-tutorial/early-binding-and-late-binding

#include <iostream>

template <typename T>
void printValue(T value) {
	std::cout << value << '\n';
}

void printValue(double value) {
	std::cout << value << '\n';
}

void printValue(int value) {
	std::cout << value << '\n';
}

int main() {
	printValue(5);	  // direct function call to printValue(int)
	printValue<>(5);	// direct function call to printValue<int>(int)

	return 0;
}