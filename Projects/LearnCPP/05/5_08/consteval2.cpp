// https://www.learncpp.com/cpp-tutorial/constexpr-and-consteval-functions

#include <iostream>

consteval auto compileTimeEval(auto value) {
    return value;
}

constexpr int greater(int x, int y) {
    return (x > y ? x : y);
}

int main() {
    std::cout << greater(5, 6) << '\n'; // may or may not execute at compile-time
    std::cout << compileTimeEval(greater(5, 6)) << '\n'; // will execute at compile-time

    int x { 5 };
    std::cout << greater(x, 6) << " is greater!\n"; // we can still call the constexpr version at runtime if we wish

    return 0;
}