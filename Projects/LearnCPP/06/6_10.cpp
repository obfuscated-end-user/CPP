// https://www.learncpp.com/cpp-tutorial/static-local-variables/

#include <iostream>

void incrementAndPrint() {
    // int value{ 1 }; // automatic duration by default
    static int s_value{ 1 }; // static duration via static keyword.  This initializer is only executed once.
    ++s_value;
    std::cout << s_value << '\n';
} // value is destroyed here

int main() {
    incrementAndPrint();
    incrementAndPrint();
    incrementAndPrint();
    return 0;
}