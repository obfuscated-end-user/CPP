// https://www.learncpp.com/cpp-tutorial/output-with-ostream-and-ios

#include <iostream>

int main() {
    std::cout.setf(std::ios::showpos);  // turn on the std::ios::showpos flag
    std::cout << 27 << '\n';

    std::cout.setf(std::ios::showpos | std::ios::uppercase);    // turn on the std::ios::showpos and std::ios::uppercase flag
    std::cout << 1234567.89f << '\n';

    std::cout.setf(std::ios::showpos);  // turn on the std::ios::showpos flag
    std::cout << 27 << '\n';
    std::cout.unsetf(std::ios::showpos);    // turn off the std::ios::showpos flag
    std::cout << 28 << '\n';

    return 0;
}