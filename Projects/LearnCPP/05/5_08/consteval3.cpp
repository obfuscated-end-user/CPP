// https://www.learncpp.com/cpp-tutorial/constexpr-and-consteval-functions

#include <iostream>

consteval int doSomething(int x, int y) {
    x = x + 2;  // we can modify the value of non-const funtion parameters

    int z { x + y };    // we can instantiate non-const local variables
    if (x > y)
        z = z - 1;  // and then modify their values

    return z;
}

int main() {
    constexpr int g { doSomething(5, 6) };
    std::cout << g << '\n';

    return 0;
}