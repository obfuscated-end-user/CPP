// https://www.learncpp.com/cpp-tutorial/constexpr-aggregates-and-classes

#include <iostream>

class Pair {
private:
    int m_x {};
    int m_y {};

public:
    constexpr Pair(int x, int y) : m_x { x }, m_y { y } {}

    constexpr int greater() const {
        return (m_x > m_y ? m_x : m_y);
    }
};

int main() {
    constexpr Pair p { 5, 6 };  // compile error: p is not a literal type
    std::cout << p.greater();

    constexpr int g { p.greater() };
    std::cout << g;

    return 0;
}