// https://www.learncpp.com/cpp-tutorial/floating-point-and-integral-promotion/

#include <iostream>

void printDouble(double d) {
    std::cout << d;
}

// floating point promotion
int main() {
    printDouble(5.0); // no conversion necessary
    printDouble(4.0f); // numeric promotion of float to double

    return 0;
}