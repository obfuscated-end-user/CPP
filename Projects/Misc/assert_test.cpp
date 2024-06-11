#include <iostream>
#include <cassert>

int main() {
    /* int even_num = 3;

    // asserts the value of even_num must be even
    assert((even_num % 2 == 0)); */

    const int number = 1;
    /* std::cout << "Enter a number: ";
    std::cin >> number; */
    static_assert((number % 0), "Number is not even");
    return 0;
}