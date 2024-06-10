// https://www.learncpp.com/cpp-tutorial/logical-operators

#include <iostream>

int main() {
    int a = 1;
    int b = 2;
    int c = 3;
    std::cout << !a && (b || c);
    std::cout << not a and (b or c);    // https://en.cppreference.com/w/cpp/language/operator_alternative
    return 0;
}