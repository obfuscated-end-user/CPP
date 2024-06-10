// https://www.learncpp.com/cpp-tutorial/lvalue-references

#include <iostream>

int main() {
    int x { 5 };    // x is a normal integer variable
    int& ref { x }; // ref is an lvalue reference variable that can now be used as an alias for variable x
    // int &ref { x }; // this also works, but most people attach the & to the type

    std::cout << x << '\n';     // print the value of x (5)
    std::cout << ref << '\n';   // print the value of x via ref (5)

    ++x;
    std::cout << ref << '\n';   // 6, because we updated the x variable, which in turn is referenced by the ref variable

    ++ref;
    std::cout << ref << '\n';   // 7
    std::cout << x << '\n';     // also 7, since ref references x, therefore x also gets affected

    int y { 5 };
    int& ref { y }; // valid: lvalue reference bound to a modifiable lvalue

    // const int z { 5 };
    // int& invalidRef { z };  // invalid: can't bind to a non-modifiable lvalue
    // int& invalidRef2 { 0 }; // invalid: can't bind to an r-value

    // double y { 6.0 };
    // int& invalidRef { y }; // invalid; reference to int cannot bind to double variable
    // double& invalidRef2 { x }; // invalid: reference to double cannot bind to int variable

    return 0;
}