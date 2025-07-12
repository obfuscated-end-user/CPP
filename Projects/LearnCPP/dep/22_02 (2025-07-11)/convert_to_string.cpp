// https://www.learncpp.com/cpp-tutorial/stdstring-construction-and-destruction

#include <iostream>
#include <sstream>
#include <string>

template <typename T>
inline std::string toString(T tX) {
	std::ostringstream oStream;
	oStream << tX;
	return oStream.str();
}

int main() {
	std::string sFour { toString(4) };
	std::string sSixPointSeven { toString(6.7) };
	std::string sA { toString('A') };
	std::cout << sFour << '\n';
	std::cout << sSixPointSeven << '\n';
	std::cout << sA << '\n';

	return 0;
}