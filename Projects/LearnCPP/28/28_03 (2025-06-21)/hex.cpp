// https://www.learncpp.com/cpp-tutorial/output-with-ostream-and-ios

#include <iostream>

int main() {
	std::cout.unsetf(std::ios::dec);	// turn off decimal output
	std::cout.setf(std::ios::hex);	  // turn on hexadecimal output
	std::cout << 27 << '\n';

	// Turn on std::ios::hex as the only std::ios::basefield flag
	std::cout.setf(std::ios::hex, std::ios::basefield);
	std::cout << 27 << '\n';

	return 0;
}