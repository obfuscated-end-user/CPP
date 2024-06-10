// https://www.learncpp.com/cpp-tutorial/boolean-values

#include <iostream>

int main() {
    bool b1 { true };
    bool b2 { false };
    b1 = false;
    bool b3 {}; // default initialize to false
    std::cout << b3 << std::endl;

    std::cout << true << '\n';
    std::cout << false << '\n';
    std::cout << std::boolalpha; // print bools as true or false
    std::cout << true << '\n';
    std::cout << false << '\n';
    return 0;
}