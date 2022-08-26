// https://www.learncpp.com/cpp-tutorial/user-defined-namespaces-and-the-scope-resolution-operator/

#include <iostream>
// #include "foo.cpp" // fucking manual shit

int doSomething(int x, int y); // forward declaration for doSomething

int main() {
    std::cout << doSomething(4, 3) << '\n'; // which doSomething will we get?
    return 0;
}