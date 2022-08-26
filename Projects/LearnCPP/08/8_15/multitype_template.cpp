// https://www.learncpp.com/cpp-tutorial/function-templates-with-multiple-template-types/

#include <iostream>

template <typename T, typename U> // We're using two template type parameters named T and U
/* T max(T x, U y) { // x can resolve to type T, and y can resolve to type U
    return (x > y) ? x : y; // uh oh, we have a narrowing conversion problem here
} */

// auto to remove the narrowing conversion shit
auto max(T x, U y) {
    return (x > y) ? x : y;
}

// another way of doing this, available in c++20 onwards:
auto max2(auto x, auto y) {
    return (x > y) ? x : y;
    // this does the same thing as the previous one.
    // this also sends a dumbass warning in the terminal.
}

int main() {
    std::cout << max(2, 3.5) << '\n';
    std::cout << max2(2, 3.5) << '\n';
    return 0;
}