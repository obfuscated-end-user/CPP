// https://www.learncpp.com/cpp-tutorial/function-templates/

#include <iostream>

template <typename T> // this is the template parameter declaration
// template <class T>  // this also works
T max(T x, T y) { // this is the function template definition for max<T>
    return (x > y) ? x : y;
}

int main() {
    std::cout << max(20, 40) << '\n';
    std::cout << max(4.2, 2.991) << '\n';
    // std::cout << max(6, 2.991) << '\n';     // won't work
    return 0;
}