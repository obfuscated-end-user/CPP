// https://www.learncpp.com/cpp-tutorial/return-by-reference-and-return-by-address

#include <iostream>
#include <string>

// Takes two std::string objects, returns the one that comes first alphabetically
const std::string& firstAlphabetical(const std::string& a, const std::string& b) {
	return (a < b) ? a : b; // We can use operator< on std::string to determine which comes first alphabetically
}

int main() {
	std::string hello { "Hello" };
	std::string world { "World" };

	std::cout << firstAlphabetical(hello, world);
	return 0;
}