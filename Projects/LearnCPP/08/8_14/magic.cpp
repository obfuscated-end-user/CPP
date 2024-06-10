// https://www.learncpp.com/cpp-tutorial/function-template-instantiation

#include <iostream>

template <typename T>
T max(T x, T y) {
    std::cout << "called max<int>(int, int)\n";
    return (x > y) ? x : y;
}

int max(int x, int y) {
    std::cout << "called max(int, int)\n";
    return (x > y) ? x : y;
}

int main() {
    std::cout << max<int>(1, 2) << '\n'; // selects max<int>(int, int)
    std::cout << max<>(1, 2) << '\n';    // deduces max<int>(int, int) (non-template functions not considered)
    std::cout << max(1, 2) << '\n';      // calls function max(int, int)
    return 0;
}