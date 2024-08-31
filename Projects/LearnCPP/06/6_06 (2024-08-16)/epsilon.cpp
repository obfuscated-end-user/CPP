// https://www.learncpp.com/cpp-tutorial/relational-operators-and-floating-point-comparisons

#include <algorithm>
#include <cmath>
#include <iostream>

// Our own constexpr implementation of std::abs (for use prior to C++23)
// In C++23, use std::abs
// constAbs() can be called like a normal function, but can handle different types of values (e.g. int, double, etc...)
template <typename T>
constexpr T constAbs(T x) {
    return (x < 0 ? -x : x);
}

// absEpsilon is an absolute value
bool approximatelyEqualAbs(double a, double b, double absEpsilon) {
    // if the distance between a and b is less than or equal to absEpsilon, then a and b are "close enough"
    return std::abs(a - b) <= absEpsilon;
}

// Return true if the difference between a and b is within epsilon percent of the larger of a and b
constexpr bool approximatelyEqualRel(double a, double b, double relEpsilon) {
    return (std::abs(a - b) <= (std::max(std::abs(a), std::abs(b)) * relEpsilon));
}

// Return true if the difference between a and n is less than or equal to absEpsilon, or within relEpsilon percent of the larger of a and b
constexpr bool approximatelyEqualAbsRel(double a, double b, double absEpsilon, double relEpsilon) {
    // Check if the numbers are really close -- needed when comparing numbers near zero
    if (std::abs(a - b) <= absEpsilon)
        return true;
    // Otherwise fall back to Knuth's algorithm
    return approximatelyEqualRel(a, b, relEpsilon);
}

int main() {
    // a is really close to 1.0, but has rounding errors
    constexpr double a { 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 };

    constexpr double relEps { 1e-8 };
    constexpr double absEps { 1e-12 };

    std::cout << std::boolalpha;

    constexpr bool same { approximatelyEqualAbsRel(a, 1.0, absEps, relEps) };
    std::cout << same << '\n';

    // compare a (1.0) to 1.0 (true)
    std::cout << approximatelyEqualRel(a, 1.0, relEps) << '\n';
    // compate a - 1.0 (almost 0.0) to 0.0 (false)
    std::cout << approximatelyEqualRel(a - 1.0, 0.0, relEps) << '\n';
    
    // compare "almost 1.0" to 1.0 (true)
    std::cout << approximatelyEqualAbsRel(a, 1.0, absEps, relEps) << '\n';
    // compare "almost 0.0" to 0.0 (true)
    std::cout << approximatelyEqualAbsRel(a - 1.0, 0.0, absEps, relEps) << '\n';

    return 0;
}