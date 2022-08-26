// https://www.learncpp.com/cpp-tutorial/pass-by-address-part-2/

#include <iostream>
#include <cstddef> // for NULL

void print(int x) { // this function accepts an integer
	std::cout << "print(int): " << x << '\n';
}

void print(int* ptr) { // this function accepts an integer pointer
	std::cout << "print(int*): " << (ptr ? "non-null\n" : "null\n");
}

int main() {
	int x{ 5 };
	int* ptr{ &x };

	print(ptr); // always calls print(int*) because ptr has type int* (good)
	print(0); // always calls print(int) because 0 is an integer literal (may or may not be what we expect)
	print(NULL); // most likely calls print(int), but could call print(int*) depending on how NULL is defined (definitely not what we want)
	print(nullptr); // always calls print(int*) because nullptr only converts to a pointer type (good)

	return 0;
}

// i don't know why it doesn't work for me