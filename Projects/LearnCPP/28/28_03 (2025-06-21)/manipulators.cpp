// https://www.learncpp.com/cpp-tutorial/output-with-ostream-and-ios

#include <iostream>

int main() {
	std::cout << std::hex << 27 << '\n';	// print 27 in hex
	std::cout << 28 << '\n';				// we're still in hex
	std::cout << std::dec << 29 << '\n';	// back to decimal

	return 0;
}