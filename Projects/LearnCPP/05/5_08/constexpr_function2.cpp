// https://www.learncpp.com/cpp-tutorial/constexpr-and-consteval-functions

#include <iostream>

// keyword constexpr has no effect?
constexpr int greater(int x, int y) {
    return (x > y ? x : y);
}

int main() {
    // both not constexpr
    int x { 5 };
    int y { 6 };

    std::cout << greater(x, y) << " is greater!\n";
    return 0;
}