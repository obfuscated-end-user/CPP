// https://www.learncpp.com/cpp-tutorial/input-with-istream

#include <iostream>

int main() {
	char strBuf[100] {};
	std::cin.getline(strBuf, 100);
	std::cout << strBuf << '\n';
	std::cout << std::cin.gcount() << " characters were read" << '\n';

	return 0;
}