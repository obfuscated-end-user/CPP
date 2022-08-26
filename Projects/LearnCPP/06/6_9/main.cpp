#include <iostream>
#include "constants.h" // include a copy of each constant in this file

int main() {
    std::cout << "Enter a radius: ";
    int radius{};
    std::cin >> radius;
    std::cout << "The circumference is: " << 2.0 * radius * constants::pi << '\n';
    return 0;
}