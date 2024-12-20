// https://www.learncpp.com/cpp-tutorial/class-templates-with-member-functions

#include <iostream>

template <typename T>
struct Pair {
    T first {};
    T second {};
};

// Here's a deduction guide for our pair (required in C++17 or older)
// Pair objects initialized with arguments of type T and T should deduce to Pair<T>
template <typename T>
Pair(T, T) -> Pair<T>;

int main() {
    Pair<int> p1 { 5, 6 };          // instantiatees Pair<int> and creates object p1
    std::cout << p1.first << ' ' << p1.second << '\n';

    Pair<double> p2 { 1.2, 3.4 };   // instantiatees Pair<double> and creates object p2
    std::cout << p2.first << ' ' << p2.second << '\n';

    Pair<double> p3 { 7.8, 9.0 };   // creates object p3 using prior definition for Pair<double>
    std::cout << p3.first << ' ' << p3.second << '\n';

    return 0;
}