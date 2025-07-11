// https://www.learncpp.com/cpp-tutorial/stdstring-and-stdwstring
// ignore this slop

#include <iostream>
#include <string.h>

int main() {
	char* strHello { new char[7] };
	strcpy(strHello, "hello!");

	std::cout << strHello << '\n';

	delete[] strHello;

	return 0;
}