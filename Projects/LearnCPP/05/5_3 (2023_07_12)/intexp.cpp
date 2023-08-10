// https://www.learncpp.com/cpp-tutorial/remainder-and-exponentiation

#include <cassert>
#include <cstdint> // for std::int64_t
#include <iostream>

// note: exp must be non-negative
// note: does not perform range/overflow checking, use with caution
constexpr std::int64_t powint(std::int64_t base, int exp) {
    assert(exp >= 0 && "powint: exp parameter has negative value");

    // handle 0 case
    if (base == 0)
        // return 1, else 0 (as 0 to raised to anything is still 0)
        return (exp == 0) ? 1 : 0;

    std::int64_t result = 1;
    while (exp > 0) {
        if (exp & 1) // if exp is odd, uses bitwise and
            result *= base;
        exp /= 2;
        base *= base;
    }

    return result;
}

int main(int argc, char const *argv[]) {
    std::cout << powint(7, 12) << '\n'; // 7^12
    return 0;
}