// https://www.learncpp.com/cpp-tutorial/input-with-istream

#include <iostream>

int main() {
    char strBuf[11] {};
    std::cin.get(strBuf, 11);
    std::cout << strBuf << '\n';

    return 0;
}