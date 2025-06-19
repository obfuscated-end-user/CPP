// https://www.learncpp.com/cpp-tutorial/uncaught-exceptions-catch-all-handlers

#include <iostream>

int main() {
    try {
        throw 5;    // throw an int exception
    } catch (double x) {
        std::cout << "We caught an exception of type double: " << x << '\n';
    } catch (...) {
        std::cout << "We caught an exception of an undetermined type\n";
    }

    return 0;
}