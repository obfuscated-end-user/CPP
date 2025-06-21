// https://www.learncpp.com/cpp-tutorial/input-with-istream

#include <iostream>

int main() {
    char strBuf[11] {};
    // Read up to 10 characters
    std::cin.get(strBuf, 11);
    std::cout << strBuf << '\n';

    // Read up to 10 more characters
    std::cin.get(strBuf, 11);
    std::cout << strBuf << '\n';
    return 0;
}