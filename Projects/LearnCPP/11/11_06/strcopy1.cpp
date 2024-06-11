// https://www.learncpp.com/cpp-tutorial/c-style-strings

#include <cstring>
#include <iostream>

int main() {
    char source[]{ "Copy this!" };
    char dest[50];
    std::strcpy(dest, source);
    std::cout << dest << '\n'; // prints "Copy this!"

    return 0;
}