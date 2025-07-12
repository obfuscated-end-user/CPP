// https://www.learncpp.com/cpp-tutorial/stdstring-construction-and-destruction

#include <iostream>
#include <sstream>
#include <string>

template <typename T>
inline bool fromString(const std::string& sString, T& tX) {
	std::istringstream iStream(sString);
	return !(iStream >> tX).fail();	// extract value into tX, return succes or not
}

int main() {
	double dX;
	if (fromString("3.4", dX))
		std::cout << dX << '\n';
	if (fromString("ABC", dX))
		std::cout << dX << '\n';

	return 0;
}