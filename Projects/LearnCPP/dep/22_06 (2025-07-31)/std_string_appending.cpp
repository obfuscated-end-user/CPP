// https://www.learncpp.com/cpp-tutorial/stdstring-appending

#include <iostream>
#include <string>

int main() {
	std::string sString { "one" };

	sString += std::string { " two" };

	std::string sThree { " three" };
	sString.append(sThree);

	std::cout << sString << '\n';

	return 0;
}