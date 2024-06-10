// https://www.learncpp.com/cpp-tutorial/literals

#include <iostream>

int main() {
    float f { 4.1f }; // use 'f' suffix so the literal is a float and matches variable type of float
    double d { 4.1 }; // change variable to type double so it matches the literal type double

    std::cout << "f: " << f << " d: " << d << std::endl;

    double pi { 3.14159 }; // 3.14159 is a double literal in standard notation
    double avogadro { 6.02e23 }; // 6.02 x 10^23 is a double literal in scientific notation
    double electron { 1.6e-19 }; // charge on an electron is 1.6 x 10^-19
    return 0;
}