// https://www.learncpp.com/cpp-tutorial/pass-by-address/

#include <iostream>

void print(int* ptr) {
	std::cout << *ptr;
}

int main() {
	int x{ 5 };
	print(&x);

	int* myptr {};
	print(myptr);   // fuck you

	return 0;
}