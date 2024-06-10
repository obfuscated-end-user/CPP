// https://www.learncpp.com/cpp-tutorial/sharing-global-constants-across-multiple-files-using-inline-variables

#include <iostream>
#include "constants.h"

int main() {
    std::cout << "Enter a radius: ";
    int radius{};
    std::cin >> radius;
    std::cout << "The circumference is: " << 2.0 * radius * constants::pi << '\n';
    return 0;
}