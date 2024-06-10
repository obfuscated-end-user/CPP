// https://www.learncpp.com/cpp-tutorial/fixed-width-integers-and-size-t

#include <cstdint> // for fixed-width integers
#include <iostream>

int main() {
    std::int16_t i{5};
    std::cout << sizeof(i) << '\n';

    std::uint_fast16_t sometype { 0 };
    --sometype; // intentionally overflow to invoke wraparound behavior
    // std::cout << sometype;

    std::cout << sizeof(int) + sizeof(double) << '\n';

    std::cout << sizeof(std::size_t) << '\n';
    return 0;
}