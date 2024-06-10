// https://www.learncpp.com/cpp-tutorial/class-templates

#include <iostream>

template <typename T>
struct Pair {
    T first{};
    T second{};
};

template <typename T>
constexpr T max(Pair<T> p) {
    return (p.first > p.second ? p.first : p.second);
}

int main() {
    Pair<int> p1{ 5, 6 };
    std::cout << max<int>(p1) << " is larger\n"; // explicit call to max<int>

    Pair<double> p2{ 1.2, 3.4 };
    std::cout << max(p2) << " is larger\n"; // call to max<double> using template argument deduction (prefer this)

    return 0;
}