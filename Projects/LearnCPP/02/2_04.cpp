// https://www.learncpp.com/cpp-tutorial/introduction-to-function-parameters-and-arguments

#include <iostream>

int add(int x, int y) {
    return x + y;
}

int doubleInteger(int x) {
    return x * 2;
}

// Write a function called doubleNumber() that takes one integer parameter. The function should return double the value of the parameter.
int doubleNumber(int x) {
    return 2 * x;
}

int main() {
    // Write a complete program that reads an integer from the user, doubles it using the doubleNumber() function you wrote in the previous quiz question, and then prints the doubled value out to the console.
    std::cout << doubleInteger(add(1, 2));
    return 0;
}