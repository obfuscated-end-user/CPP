// https://www.learncpp.com/cpp-tutorial/output-with-ostream-and-ios

#include <iostream>

int main() {
    std::cout << 27 << '\n';

    std::cout.setf(std::ios::dec, std::ios::basefield);
    std::cout << 27 << '\n';

    std::cout.setf(std::ios::oct, std::ios::basefield);
    std::cout << 27 << '\n';

    std::cout.setf(std::ios::hex, std::ios::basefield);
    std::cout << 27 << '\n';

    std::cout << std::dec << 27 << '\n';
    std::cout << std::oct << 27 << '\n';
    std::cout << std::hex << 27 << '\n';

    return 0;
}