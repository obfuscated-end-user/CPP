// https://www.learncpp.com/cpp-tutorial/floating-point-numbers/

#include <iostream>
#include <iomanip> // for output manipulator std::setprecision()

int main() {
	std::cout << 5.0 << '\n';
	std::cout << 6.7f << '\n';
	std::cout << 9876543.21 << "\n\n";

    std::cout << 9.87654321f << '\n';
    std::cout << 987.654321f << '\n';
    std::cout << 987654.321f << '\n';
    std::cout << 9876543.21f << '\n';
    std::cout << 0.0000987654321f << "\n\n";

    std::cout << std::setprecision(16); // show 16 digits of precision
    std::cout << 3.33333333333333333333333333333333333333f <<'\n'; // f suffix means float
    std::cout << 3.33333333333333333333333333333333333333 << "\n\n"; // no suffix means double

    double d{0.1};
    std::cout << d << '\n'; // use default cout precision of 6
    std::cout << std::setprecision(17);
    std::cout << d << "\n\n";

    std::cout << std::setprecision(17);
    double d1{ 1.0 };
    std::cout << d1 << '\n';
    double d2{ 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 }; // should equal 1.0
    std::cout << d2 << "\n\n";

    double zero {0.0};
    double posinf { 5.0 / zero }; // positive infinity
    std::cout << posinf << '\n';
    double neginf { -5.0 / zero }; // negative infinity
    std::cout << neginf << '\n';
    double nan { zero / zero }; // not a number (mathematically invalid)
    std::cout << nan << "\n\n";

	return 0;
}