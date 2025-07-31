// https://www.learncpp.com/cpp-tutorial/stdstring-inserting

#include <iostream>
#include <string>

int main() {
	std::string sString("aaaa");

	sString.insert(2, "bcdef", 3);
	std::cout << sString << std::endl;

	return 0;
}