// https://www.learncpp.com/cpp-tutorial/signed-integers

#include <iostream>

int main() {
    // assume 4 bytes integers
    int x = 2'147'483'647; // the maximum value of a 4-byte signed integer
    std::cout << x << '\n';

    x = x + 1; // integer overflow, undefined behavior
    std::cout << x << '\n';

    // division test
    std::cout << 20 / 4 << '\n';
    std::cout << 8 / 5 << '\n';

    return 0;
}