// https://www.learncpp.com/cpp-tutorial/stdstring-appending

#include <iostream>
#include <string>

int main() {
	std::string sString { "one " };

	sString.append("threefour", 5);
	std::cout << sString << '\n';

	return 0;
}