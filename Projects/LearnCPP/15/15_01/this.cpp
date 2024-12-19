// https://www.learncpp.com/cpp-tutorial/the-hidden-this-pointer-and-member-function-chaining

#include <iostream>

class Simple {
private:
    int m_id {};

public:
    Simple(int id) : m_id { id } {}

    int getID() const {
        return m_id;
    }

    void setID(int id) {
        m_id = id;
    }

    void print() const {
        // use `this` pointer to access the implicit object and operator-> to select member m_id
        std::cout << this->m_id;
        // std::cout << m_id;
        // std::cout << (*this).m_id;
    }
};

int main() {
    Simple simple { 1 };
    simple.setID(2);

    simple.print();

    return 0;
}