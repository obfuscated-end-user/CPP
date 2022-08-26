// https://www.learncpp.com/cpp-tutorial/using-an-integrated-debugger-the-call-stack/

#include <iostream>

void a() {
	std::cout << "a() called\n";
}

void b() {
	std::cout << "b() called\n";
	a();
}

int main() {
	a();
	b();
	return 0;
}