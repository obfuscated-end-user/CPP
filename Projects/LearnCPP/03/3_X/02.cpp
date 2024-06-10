// https://www.learncpp.com/cpp-tutorial/chapter-3-summary-and-quiz

#include <iostream>

int readNumber() {
	std::cout << "Please enter a number: ";
	int x {};
	std::cin >> x;
	return x;
}

void writeAnswer(int x) {
	std::cout << "The quotient is: " << x << '\n';
}

int main() {
	int x{ };
	int y{ };
	x = readNumber();
	y = readNumber(); // x is being read twice
	writeAnswer(x/y);

	return 0;
}