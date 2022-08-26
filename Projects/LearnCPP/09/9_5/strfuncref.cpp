// https://www.learncpp.com/cpp-tutorial/pass-by-lvalue-reference/

#include <iostream>
#include <string>

void printValue(std::string& y) { // type changed to std::string&
    std::cout << y << '\n';
} // y is destroyed here

int main() {
    std::string x { "Hello, world!" };
    printValue(x); // x is now passed by reference into reference parameter y (inexpensive)

    return 0;
}