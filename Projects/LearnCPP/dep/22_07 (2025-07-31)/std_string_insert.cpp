// https://www.learncpp.com/cpp-tutorial/stdstring-inserting

#include <iostream>
#include <string>

int main() {
	std::string sString("aaaa");
	std::cout << sString << std::endl;

	sString.insert(2, std::string("bbbb"));
	std::cout << sString << std::endl;

	sString.insert(4, "cccc");
	std::cout << sString << std::endl;

	return 0;
}