// https://www.learncpp.com/cpp-tutorial/stdstring-appending

#include <iostream>
#include <string>

int main() {
	std::string sString { "one" };

	sString += " two";
	sString.append(" three");
	std::cout << sString << '\n';

	return 0;
}