// https://www.learncpp.com/cpp-tutorial/function-template-instantiation

#include <iostream>

template <typename T>
T max(T x, T y) {
    return (x > y) ? x : y;
}

int main() {
    std::cout << max<int>(1, 2) << '\n'; // instantiates and calls function max<int>(int, int)
    std::cout << max<int>(1.0, 2) << '\n';
    std::cout << max<double>(1.4, 23300.1929) << '\n';
    std::cout << max<char>(56, 78) << '\n';
    return 0;
}