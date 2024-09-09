// https://www.learncpp.com/cpp-tutorial/the-benefits-of-data-hiding-encapsulation

#include <iostream>
#include <string>

class Yogurt {
    std::string m_flavor { "vanilla" };

public:
    void setFlavor(std::string_view flavor) {
        m_flavor = flavor;
    }

    const std::string& getFlavor() const {
        return m_flavor;
    }

    // Worst: member function print() uses direct access to m_flavor when getter exists
    /* void print() const {
        std::cout << "The yogurt has flavor " << m_flavor << '\n';
    } */

    // Better: member function print() has no direct access to members
    void print(std::string_view prefix) const {
        std::cout << prefix << ' ' << getFlavor() << '\n';
    }
};

// Best: non-member functon print() is not part of the class interface
void print(const Yogurt& y) {
    std::cout << "The yogurt has flavor " << y.getFlavor() << '\n';
}

int main() {
    Yogurt y {};
    y.setFlavor("cherry");
    // y.print();
    // y.print("The yogurt has flavor");
    print(y);

    return 0;
}