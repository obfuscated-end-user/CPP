// https://www.learncpp.com/cpp-tutorial/output-with-ostream-and-ios

#include <iostream>

int main() {
    std::cout << 5 << '\n';

    std::cout.setf(std::ios::showpos);
    std::cout << 5 << '\n';

    std::cout << std::noshowpos << 5 << '\n';

    std::cout << std::showpos << 5 << '\n';

    return 0;
}