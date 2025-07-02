// https://www.learncpp.com/cpp-tutorial/stream-classes-for-strings

#include <iostream>
#include <sstream>

int main() {
	std::stringstream os {};
	os << "12345 67.89\n";
	std::cout << os.str();

	std::string strValue {};
	os >> strValue;

	std::string strValue2 {};
	os >> strValue2;

	// print the numbers separated by a dash
	std::cout << strValue << " - " << strValue2 << '\n';

	return 0;
}