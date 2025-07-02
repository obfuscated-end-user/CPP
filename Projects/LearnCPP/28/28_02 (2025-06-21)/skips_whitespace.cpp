// https://www.learncpp.com/cpp-tutorial/input-with-istream

#include <iostream>

int main() {
	char ch {};
	while (std::cin >> ch)
		std::cout << ch;

	return 0;
}