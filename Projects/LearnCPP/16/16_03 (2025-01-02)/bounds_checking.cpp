// https://www.learncpp.com/cpp-tutorial/stdvector-and-the-unsigned-length-and-subscript-problem

#include <iostream>
#include <vector>

int main() {
	std::vector prime { 2, 3, 5, 7, 11 };

	std::cout << prime[3];	  // print the value of element with index 3 (7)
	std::cout << prime[9];	  // invalid index (undefined behavior)

	std::cout << prime.at(3);	// print the value of element with index 3
	std::cout << prime.at(9);	// invalid index (throws exception)

	return 0;
}