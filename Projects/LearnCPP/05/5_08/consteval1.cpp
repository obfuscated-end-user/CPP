// https://www.learncpp.com/cpp-tutorial/constexpr-and-consteval-functions

#include <iostream>

consteval int greater(int x, int y) {
    return (x > y ? x : y);
}

int main() {
    constexpr int g { greater(5, 6) };
    std::cout << g << '\n'; // ok: will evaluate at compile-time

    std::cout << greater(5, 6) << " is greater!\n"; // ok: will evaluate at compile-time

    int x { 5 };    // not constexpr
    std::cout << greater(x, 6) << " is greater!\n"; // error: consteval functions must evaluate at compile-time

    return 0;
}