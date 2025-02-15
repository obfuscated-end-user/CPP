// https://www.learncpp.com/cpp-tutorial/introduction-to-destructors

#include <iostream>

class Simple {
private:
    int m_id {};

public:
    Simple(int id) : m_id { id } {
        std::cout << "Constructing Simple " << m_id << '\n';
    }

    ~Simple() { // here's our destructor
        std::cout << "Destructing Simple " << m_id << '\n';
    }

    int getID() const {
        return m_id;
    }

};

int main() {
    // Allocate a Simple
    Simple simple1 { 1 };
    {
        Simple simple2 { 2 };
    }   // simple 2 dies here

    return 0;
}   // simple 1 dies here