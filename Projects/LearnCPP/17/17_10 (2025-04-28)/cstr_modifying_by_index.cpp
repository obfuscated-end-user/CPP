// https://www.learncpp.com/cpp-tutorial/c-style-strings

#include <iostream>

int main() {
	char str[] { "string" };
	std::cout << str << '\n';
	str[1] = 'p';
	std::cout << str << '\n';

	return 0;
}