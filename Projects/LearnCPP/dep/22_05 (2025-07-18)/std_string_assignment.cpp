// https://www.learncpp.com/cpp-tutorial/stdstring-assignment-and-swapping

#include <iostream>
#include <string>

int main() {
	std::string sString {};

	// Assign a string value
	sString = std::string("One");
	std::cout << sString << '\n';

	const std::string sTwo("Two");
	sString.assign(sTwo);
	std::cout << sString << '\n';

	// Assign a C-style string
	sString = "Three";
	std::cout << sString << '\n';

	// Assign a char
	sString = '5';
	std::cout << sString << '\n';

	// Chain assignment
	std::string sOther {};
	sString = sOther = "Six";
	std::cout << sString << ' ' << sOther << '\n';

	return 0;
}