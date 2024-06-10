// https://www.learncpp.com/cpp-tutorial/remainder-and-exponentiation

#include <cassert>
#include <cstdint>
#include <iostream>
#include <limits> // for std::numeric_limits

constexpr std::int64_t powint_safe(std::int64_t base, int exp) {
    assert(exp >= 0 && "powint_safe: exp parameter has negative value");

    // handle 0 case
    if (base == 0)
        return (exp == 0) ? 1 : 0;

    std::int64_t result = 1;
    // to make the range checks easier, we'll ensure base is positive
    // we'll flip the result at the end if needed
    bool negativeResult = false;

    if (base < 0) {
        base -= base;
        negativeResult = exp & 1;
    }

    while (exp > 0) {
        if (exp & 1) {
            if (result > std::numeric_limits<std::int64_t>::max() / base) {
                std::cerr << "powint_safe(): result overflowed\n";
                return std::numeric_limits<std::int64_t>::max();
            }
            result *= base;
        }
        exp /= 2;

        // if we're done get out here
        if (exp <= 0)
            break;

        // the following only needs to execute if we're going to iterate again
        // check if base will overflow when multiplied by base
        if (base > std::numeric_limits<std::int64_t>::max() / base) {
            std::cerr << "powint_safe(): base overflowed\n";
            return std::numeric_limits<std::int64_t>::max();
        }
        base *= base;
    }

    if (negativeResult)
        return -result;

    return result;
}

int main(int argc, char const *argv[]) {
    std::cout << powint_safe(7, 12) << '\n'; // 7^12 = 13841287201
    std::cout << powint_safe(7, 0) << '\n'; // 7^0 = 1
    std::cout << powint_safe(3, 12) << '\n'; // 3^12 = 531441
    std::cout << powint_safe(std::numeric_limits<std::int64_t>::max(), 2) << '\n'; // base overflowed
    std::cout << powint_safe(7, -1) << '\n'; // 7^-1 = error
    std::cout << std::numeric_limits<std::int64_t>::max(); // 9223372036854775807
    return 0;
}
