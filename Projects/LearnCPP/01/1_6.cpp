// https://www.learncpp.com/cpp-tutorial/uninitialized-variables-and-undefined-behavior/

#include <iostream>

int main()
{
    // undefined variable
    int x {};
    std::cout << x;
}