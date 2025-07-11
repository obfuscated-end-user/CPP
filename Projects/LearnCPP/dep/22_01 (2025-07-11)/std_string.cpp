// https://www.learncpp.com/cpp-tutorial/stdstring-and-stdwstring
// obviously doesn't work

#include <iostream>
#include <string>

int main() {
	std::wstring wide { "あ" };
	std::cout << wide;

	return 0;
}