// https://www.learncpp.com/cpp-tutorial/function-template-instantiation

// this program doesn't work
#include <iostream>
#include <string>

template <typename T>
T addOne(T x) {
    return x + 1;
}

int main() {
    std::string hello { "Hello, world!" };
    std::cout << addOne(hello) << '\n';
    return 0;
}