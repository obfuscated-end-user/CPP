// https://www.learncpp.com/cpp-tutorial/stdstring-inserting

#include <iostream>
#include <string>

int main() {
	std::string sString("aaaa");

	const std::string sInsert("01234567");
	sString.insert(2, sInsert, 3, 4);	// insert substring of sInsert from index [3,7) into sString at index 2
	std::cout << sString << std::endl;

	return 0;
}