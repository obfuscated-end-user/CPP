// https://www.learncpp.com/cpp-tutorial/input-with-istream

#include <iomanip>
#include <iostream>

int main() {
    char buf[10] {};
    std::cin >> std::setw(10) >> buf;

    std::cout << buf << '\n';

    return 0;
}