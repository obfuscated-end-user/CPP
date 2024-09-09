// https://www.learncpp.com/cpp-tutorial/the-benefits-of-data-hiding-encapsulation

#include <iostream>

struct Something1 {
private:
    int m_value1 {};
    int m_value2 {};
    int m_value3 {};

public:
    void setValue1(int value) {
        m_value1 = value;
    }

    int getValue1() const {
        return m_value1;
    }
};

struct Something2 {
private:
    int m_value[3] {};  // note: we changed the implementation of this class!

public:
    // We have to update any member functions to reflect the new implementation
    void setValue1(int value) {
        m_value[0] = value;
    }

    int getValue1() const {
        return m_value[0];
    }
};

int main() {
    /* Something something;
    something.value1 = 5;
    std::cout << something.value1 << '\n'; */

    Something1 something1;
    something1.setValue1(5);
    std::cout << something1.getValue1() << '\n';

    Something1 something2;
    something2.setValue1(5);
    std::cout << something2.getValue1() << '\n';

    return 0;
}