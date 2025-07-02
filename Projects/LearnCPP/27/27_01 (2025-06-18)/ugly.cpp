// https://www.learncpp.com/cpp-tutorial/the-need-for-exceptions

#include <iostream>

double divide(int x, int y, bool& outSuccess) {
	if (y == 0) {
		outSuccess = false;
		return 0.0;
	}
	outSuccess = true;
	return static_cast<double>(x) / y;
}

int main() {
	bool success {};	// we must now pass in a bool value to see if the call was successful
	double result { divide(5, 3, success) };

	if (!success)	// and check it before we use the result
		std::cerr << "An error occurred" << std::endl;
	else
		std::cout << "The answer is " << result << '\n';

	return 0;
}