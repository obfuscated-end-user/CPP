// https://www.learncpp.com/cpp-tutorial/c-style-strings/

#include <iostream>

int main() {
    char myString[]{ "string" };
    myString[1] = 'p';
    std::cout << myString << '\n';

    return 0;
}