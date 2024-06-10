// https://www.learncpp.com/cpp-tutorial/numeric-conversions

#include <iostream>

int main() {
    int i{ 30000 };
    char c = i; // chars have range -128 to 127
    std::cout << static_cast<int>(c);
    return 0;
}