// https://www.learncpp.com/cpp-tutorial/inline-functions-and-variables

#include <iostream>

// don't use the inline keyword
inline int min(int x, int y) {
    return (x < y) ? x : y;
}

int main() {
    std::cout << min(5, 6) << '\n';
    std::cout << min(3, 2) << '\n';

    return 0;
}