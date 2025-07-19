// https://www.learncpp.com/cpp-tutorial/stdstring-assignment-and-swapping

#include <iostream>
#include <string>

int main() {
	std::string sSource("abcdefg");
	std::string sDest {};

	sDest.assign(sSource, 2, 4);	// assign a substring of source from index 2 of length 4
	std::cout << sDest << '\n';

	sDest.assign("abcdefg", 4);
	std::cout << sDest << '\n';

	sDest.assign(4, 'g');
	std::cout << sDest << '\n';

	return 0;
}