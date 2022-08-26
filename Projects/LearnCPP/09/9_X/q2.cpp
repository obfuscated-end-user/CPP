// https://www.learncpp.com/cpp-tutorial/chapter-9-summary-and-quiz/

#include <iostream>

int main() {
	int x{ 5 };
	int y{ 6 };

	int& ref{ x };  // ref is referencing x
	++ref;          // increment x through the reference variable. x = 6
	ref = y;        // assign the value of x to that of y, which is 6. this does not mean that ref is now referencing y. x is still 6
	++ref;          // increment x again. x = 7

	std::cout << x << ' ' << y;

	return 0;
}