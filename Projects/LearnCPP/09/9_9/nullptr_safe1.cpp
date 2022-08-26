// https://www.learncpp.com/cpp-tutorial/pass-by-address/

#include <iostream>

void print(int* ptr) {
    if (ptr) { // if ptr is not a null pointer
        std::cout << *ptr;
    }
}

int main() {
	int x{ 5 };
	print(&x);
	print(nullptr);

	return 0;
}