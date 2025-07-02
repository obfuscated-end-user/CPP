// https://www.learncpp.com/cpp-tutorial/c-style-array-decay

#include <iostream>

void printElement2(int arr[]) {
	// How do we ensure that arr has at least three elements?
	std::cout << arr[2] << '\n';
}

int main() {
	int a[] { 3, 2, 1 };
	printElement2(a);	// ok

	int b[] { 7, 6 };
	printElement2(b);	// compiles but produces undefined behavior

	int c { 9 };
	printElement2(&c);	// compiles but produces undefined behavior

	return 0;
}