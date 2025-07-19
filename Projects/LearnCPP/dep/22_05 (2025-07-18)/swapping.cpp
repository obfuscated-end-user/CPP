// https://www.learncpp.com/cpp-tutorial/stdstring-assignment-and-swapping

#include <iostream>
#include <string>

int main() {
	std::string sStr1("red");
	std::string sStr2("blue");

	std::cout << sStr1 << ' ' << sStr2 << '\n';
	swap(sStr1, sStr2);
	std::cout << sStr1 << ' ' << sStr2 << '\n';
	sStr1.swap(sStr2);
	std::cout << sStr1 << ' ' << sStr2 << '\n';

	return 0;
}