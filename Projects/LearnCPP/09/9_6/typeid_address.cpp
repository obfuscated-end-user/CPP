// https://www.learncpp.com/cpp-tutorial/introduction-to-pointers/

#include <iostream>
#include <typeinfo>

int main() {
	int x{ 4 };
	std::cout << typeid(&x).name() << '\n'; // print the type of &x

	return 0;
}