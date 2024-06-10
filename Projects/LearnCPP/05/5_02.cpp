// https://www.learncpp.com/cpp-tutorial/arithmetic-operators

#include <iostream>

int main() {
    /* std::cout << -(-1) << '\n';
    std::cout << -1 << '\n';
    std::cout << 5 - -3 << '\n'; // 8, not 2 */

    // integer division
    std::cout << 8 / 3 << '\n';     // 2, because 3 goes into 8 twice
    // floating point division, occurs if either one (or both) of the operands are float
    std::cout << 8 / 3.0 << '\n';   // 2.6667
    std::cout << 8.0 / 3 << '\n';   // 2.6667

    // familliar of zero
    // std::cout << 1 / 0 << '\n';

    char ch = 'a';
    std::cout << ch << '\n';
    std::cout << +ch << '\n';   // weird behavior with the unary plus operator
    return 0;
}