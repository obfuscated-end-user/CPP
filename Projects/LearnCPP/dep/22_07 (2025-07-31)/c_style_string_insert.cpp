// https://www.learncpp.com/cpp-tutorial/stdstring-inserting

#include <iostream>
#include <string>

int main() {
	std::string sString("aaaa");

	sString.insert(2, 4, 'c');
	std::cout << sString << std::endl;

	return 0;
}