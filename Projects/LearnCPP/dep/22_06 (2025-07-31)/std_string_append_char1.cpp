// https://www.learncpp.com/cpp-tutorial/stdstring-appending

#include <iostream>
#include <string>

int main() {
	std::string sString { "one" };

	sString += ' ';
	sString.push_back('2');
	std::cout << sString << '\n';

	return 0;
}