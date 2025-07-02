// https://www.learncpp.com/cpp-tutorial/stream-classes-for-strings

#include <iostream>
#include <sstream>

int main() {
	std::stringstream os {};

	constexpr int nValue { 12345 };
	constexpr double dValue { 67.89 };
	os << nValue << ' ' << dValue;

	std::string strValue1, strValue2;
	os >> strValue1 >> strValue2;

	std::cout << strValue1 << ' ' << strValue2 << '\n';

	return 0;
}