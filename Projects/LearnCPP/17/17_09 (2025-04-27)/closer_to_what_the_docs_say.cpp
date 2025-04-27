// https://www.learncpp.com/cpp-tutorial/pointer-arithmetic-and-subscripting
// https://en.cppreference.com/w/cpp/language/range-for

#include <iostream>

int main() {
    constexpr int arr[] { 9, 7, 5, 3, 1 };

    auto __begin = arr;                 // arr is our begin-expr
    auto __end = arr + std::size(arr);  // arr + std::size(arr) is our end-expr
    
    for (; __begin != __end; ++__begin) {
        auto e = *__begin;      // e is our range-declaration
        std::cout << e << ' ';  // here is our loop statement
    }

    return 0;
}