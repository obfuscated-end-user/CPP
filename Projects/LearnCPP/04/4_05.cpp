// https://www.learncpp.com/cpp-tutorial/unsigned-integers-and-why-to-avoid-them

#include <iostream>

int main() {
    unsigned short x{ 65535 }; // largest 16-bit unsigned value possible
    std::cout << "x was: " << x << '\n';

    x = 65536; // 65536 is out of our range, so we get wrap-around
    std::cout << "x is now: " << x << '\n';

    x = 65537; // 65537 is out of our range, so we get wrap-around
    std::cout << "x is now: " << x << '\n';

    unsigned int a = 2;
    unsigned int b = 4;

    std::cout << b - a << '\n';
    std::cout << a - b << '\n'; // 4294967294

    return 0;
}