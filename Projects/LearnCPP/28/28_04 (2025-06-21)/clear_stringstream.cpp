// https://www.learncpp.com/cpp-tutorial/stream-classes-for-strings

#include <iostream>
#include <sstream>

int main() {
	std::stringstream os {};
	os << "Hello ";

	os.str(""); // erase the buffer
	os.clear(); // reset error flags

	os << "World!";
	std::cout << os.str() << '\n';

	os << "Hello ";

	os.str(std::string{});  // erase the buffer
	os.clear();			 // reset error flags

	os << "World!";
	std::cout << os.str();

	return 0;
}