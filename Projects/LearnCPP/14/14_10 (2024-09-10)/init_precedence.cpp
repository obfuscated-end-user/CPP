// https://www.learncpp.com/cpp-tutorial/constructor-member-initializer-lists

#include <iostream>

class Foo {
private:
    int m_x {};     // default member initializer (will be ignored)
    int m_y { 2 };  // default member initializer (will be used)
    int m_z;        // no initializer

public:
    Foo(int x) : m_x { x } {
        std::cout << "Foo constructed\n";
    }

    void print() const {
        std::cout << "Foo(" << m_x << ", " << m_y << ", " << m_z << ")\n";
    }
};

int main() {
    Foo foo { 6 };
    foo.print();

    return 0;
}