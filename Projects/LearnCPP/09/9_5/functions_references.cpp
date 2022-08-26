// https://www.learncpp.com/cpp-tutorial/pass-by-lvalue-reference/

#include <iostream>

void printValue(int y) {
    std::cout << y << '\n';
} // y is destroyed here

int main() {
    int x { 2 };
    printValue(x); // x is passed by value (copied) into parameter y (inexpensive)

    return 0;
}