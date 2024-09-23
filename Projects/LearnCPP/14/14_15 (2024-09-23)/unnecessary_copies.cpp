// https://www.learncpp.com/cpp-tutorial/class-initialization-and-copy-elision

#include <iostream>

class Something {
    int m_x {};

public:
    Something(int x) : m_x { x } {
        std::cout << "Normmal constructor\n";
    }

    Something(const Something& s) : m_x { s.m_x } {
        std::cout << "Copy constructor\n";
    }

    void print() const {
        std::cout << "Something(" << m_x << ")\n";
    }
};

int main() {
    Something s { Something { 5 } };    // focus on this line
    s.print();

    return 0;
}