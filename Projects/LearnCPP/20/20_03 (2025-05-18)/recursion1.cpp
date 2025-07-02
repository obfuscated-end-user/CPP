// https://www.learncpp.com/cpp-tutorial/recursion

#include <iostream>

void countDown(int count) {
	std::cout << "push " << count << '\n';
	countDown(count-1); // coundDown() calls itself recursively
}

int main() {
	countDown(5);

	return 0;
}