// https://www.learncpp.com/cpp-tutorial/constexpr-aggregates-and-classes

#include <iostream>

class Pair {
private:
    int m_x {};
    int m_y {};

public:
    constexpr Pair(int x, int y) : m_x { x }, m_y { y } {}

    constexpr int greater() const {     // constexpr and const
        return (m_x > m_y ? m_x : m_y);
    }

    constexpr void reset() {            // constexpr but not const
        m_x = m_y = 0;
    }

    constexpr const int& getX() const {
        return m_x;
    }
};

// This function is constexpr
constexpr Pair zero() {
    Pair p { 1, 2 };    // p is non-const
    p.reset();          // call constexpr member function on non-const object
    return p;
}

int main() {
    constexpr Pair p2 { zero() };   // zero() mut evaluate at compile-time
    std::cout << p2.getX();         // prints 0

    return 0;
}