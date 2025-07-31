// https://www.learncpp.com/cpp-tutorial/stdstring-appending

#include <iostream>
#include <string>

int main() {
	std::string sString{ "aaa" };

	sString.append(4, 'b');
	std::cout << sString << '\n';

	return 0;
}