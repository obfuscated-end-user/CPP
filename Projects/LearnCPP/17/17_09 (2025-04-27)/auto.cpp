// https://www.learncpp.com/cpp-tutorial/pointer-arithmetic-and-subscripting

#include <iostream>

int main() {
	constexpr int arr[] { 9, 7, 5, 3, 1 };
	
	for (auto e : arr) {		// iterate from `begin` up to (but excluding) `end`
		std::cout << e << ' ';	// dereference our loop variable to get the current element
	}

	return 0;
}