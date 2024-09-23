// https://www.learncpp.com/cpp-tutorial/converting-constructors-and-the-explicit-keyword

#include <iostream>

class Dollars {
private:
    int m_dollars {};

public:
    explicit Dollars(int d) : m_dollars { d } {}

    int getDollars() const {
        return m_dollars;
    }
};

void print(Dollars d) {
    std::cout << '$' << d.getDollars();
}

int main() {
    // print(5);   // compilation error because Dollars(int) is explicit
    print(Dollars { 5 }); // ok: create Dollars and pass to print() (no conversion required)

    return 0;
}