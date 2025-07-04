// https://www.learncpp.com/cpp-tutorial/introduction-to-lambdas-anonymous-functions

#include <iostream>

int main() {
	// note: explicitly specifying this returns a double
	auto divide { [](int x, int y, bool intDivision) -> double {
		if (intDivision)
			return x / y;	// will do an implicit conversion of result to double
		else
			return static_cast<double>(x) / y;
	} };

	std::cout << divide(3, 2, true) << '\n';
	std::cout << divide(3, 2, false) << '\n';

	return 0;
}