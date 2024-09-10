// https://www.learncpp.com/cpp-tutorial/constructor-member-initializer-lists

#include <algorithm>    // for std::max()
#include <iostream>

class Foo {
private:
    int m_x {};
    int m_y {};

public:
    Foo(int x, int y)
        : m_y { std::max(x, y) }, m_x { m_y } {}   // issue on this line

    void print() const {
        std::cout << "Foo(" << m_x << ", " << m_y << ")\n";
    }
};

int main() {
    Foo foo { 6, 7 };
    foo.print();

    return 0;
}

// because m_x is defined before m_y in the class definition, m_x will be initialized first (even if it is not listed first in the member initializer list)