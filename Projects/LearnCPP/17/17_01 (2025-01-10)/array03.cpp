// https://www.learncpp.com/cpp-tutorial/introduction-to-stdarray

#include <array>
#include <iostream>

void foo(const int length) {		// length is a runtime constant
	std::array<int, length> e {};	// error: length is not a constant expression
}

int main() {
	// using a non-const variable
	int numStudents {};
	std::cin >> numStudents;			// numStudents is non-constant

	std::array<int, numStudents> {};	// error: numStudents is not a constant expression

	foo(7);

	std::array<int, 0> arr {};  // creates a zero-length std::array
	std::cout << arr.empty();	// true if arr is zero-length

	return 0;
}