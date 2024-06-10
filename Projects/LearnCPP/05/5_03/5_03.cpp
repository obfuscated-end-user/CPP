// https://www.learncpp.com/cpp-tutorial/5-3-modulus-and-exponentiation

#include <iostream>
#include <cmath>

// because c++ doesn't have exponents for integers, here is a custom function.

#include <cstdint> // for std::int64_t
#include <cassert> // for assert
// note: exp must be non-negative
std::int64_t powint(int base, int exp) {
	assert(exp >= 0 && "powint: exp parameter has negative value");
	std::int64_t result{ 1 };
	while (exp) {
		if (exp & 1)
			result *= base;
		exp >>= 1;
		base *= base;
	}
	return result;
}

int main() {
	/* std::cout << "Enter an integer: ";
	int x{};
	std::cin >> x;

	std::cout << "Enter another integer: ";
	int y{};
	std::cin >> y;

	std::cout << "The remainder is: " << x % y << '\n';

	if ((x % y) == 0)
		std::cout << x << " is evenly divisible by " << y << '\n';
	else
		std::cout << x << " is not evenly divisible by " << y << '\n'; */

    // exponents in c++
    double x{ std::pow(3.0, 4.0) }; // 3 to the 4th power
    double y = std::pow(3.0, 4.0); // 3 to the 4th power

    // using the custom function earlier
    // std::cout << powint(7, 12); // 7 to the 12th power

    std::cout << 6 + 5 * 4 % 3;

	return 0;
}