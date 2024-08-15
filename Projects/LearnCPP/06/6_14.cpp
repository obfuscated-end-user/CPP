// https://www.learncpp.com/cpp-tutorial/constexpr-and-consteval-functions
// DEAD LINK

#include <iostream>

// A constexpr function is a function whose return value may be computed at compile-time.
// "already has a fixed value before runtime"
// performs faster than regular functions?
constexpr int greater(int x, int y) {
    return (x > y ? x : y);
}

// consteval
// - Used to indicate that a function must evaluate at compile-time, otherwise a compile error will result.
// Such functions are called immediate functions.
/* consteval int greater2(int x, int y) { // function is now consteval 
    return (x > y ? x : y);
} */

int main() {
    // arguments are required to be constexpr, else the function will be evaluated at runtime.
    constexpr int x{ 5 };
    constexpr int y{ 6 };
    constexpr int g { greater(x, y) }; // will be evaluated at compile-time
    std::cout << g << " is greater!";

    /* std::cout << greater2(5, 6) << " is greater!";
    // can't do this
    std::cout << greater2(x, 6) << " is greater!"; */
    return 0;
}