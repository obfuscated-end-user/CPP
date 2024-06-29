// https://www.learncpp.com/cpp-tutorial/function-return-values-value-returning-functions

#include <iostream>

int getValue() {
    std::cout << "Enter an integer: ";
    int input;
    std::cin >> input
    // no return statement
}

int main() {
    int getValueInt = getValue(); // warning
    int mainNumber = main() + main(); // doesn't work
    std::cout << mainNumber;
    return 0;
}