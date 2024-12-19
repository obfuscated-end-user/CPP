// https://www.learncpp.com/cpp-tutorial/the-hidden-this-pointer-and-member-function-chaining

#include <iostream>

class Calc {
private:
    int m_value {};

public:
    // returning *this makes it point to this Calc object instead of doing something I don't know
    Calc& add(int value) {
        m_value += value;
        return *this;
    }

    Calc& sub(int value) {
        m_value -= value;
        return *this;
    }

    Calc& mult(int value) {
        m_value *= value;
        return *this;
    }

    int getValue() const {
        return m_value;
    }

    void reset() {
        *this = {};
    }
};

int main() {
    Calc calc {};

    calc.add(5).sub(3).mult(4);             // method chaining

    std::cout << calc.getValue() << '\n';   // prints 8

    calc.reset();

    std::cout << calc.getValue() << '\n';   // prints 0

    return 0;
}