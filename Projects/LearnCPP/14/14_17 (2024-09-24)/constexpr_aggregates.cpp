// https://www.learncpp.com/cpp-tutorial/constexpr-aggregates-and-classes

#include <iostream>

struct Pair {
    int m_x {};
    int m_y {};

    constexpr int greater() const {
        return (m_x > m_y ? m_x : m_y);
    }
};

int main() {
    constexpr Pair p { 5, 6 };          // now constexpr
    std::cout << p.greater();           // p.greater() evaluates at runtime or compile-time

    constexpr int g { p.greater() };    // p.greater() must evaluate at compile-time
    std::cout << g;

    return 0;
}