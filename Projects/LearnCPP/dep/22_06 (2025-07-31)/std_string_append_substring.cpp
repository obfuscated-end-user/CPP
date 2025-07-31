// https://www.learncpp.com/cpp-tutorial/stdstring-appending

#include <iostream>
#include <string>

int main() {
	std::string sString { "one " };

	const std::string sTemp { "twothreefour" };
	sString.append(sTemp, 3, 5);	// append substring of sTemp starting at index 3 of length 5
	std::cout << sString << '\n';

	return 0;
}