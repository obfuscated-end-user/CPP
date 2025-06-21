// https://www.learncpp.com/cpp-tutorial/output-with-ostream-and-ios

#include <iostream>

int main() {
    std::cout << 12345678.9 << '\n';

    std::cout.setf(std::ios::uppercase);
    std::cout << 12345678.9 << '\n';

    std::cout << std::nouppercase << 12345678.9 << '\n';

    std::cout << std::uppercase << 12345678.9 << '\n';

    return 0;
}