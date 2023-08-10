// https://www.learncpp.com/cpp-tutorial/overloading-the-parenthesis-operator

#include <iostream>

class Accumulator {
private:
    int m_counter = 0;

public:
    int operator()(int i) {
        return m_counter += i;
    }

    // optional
    void reset() {
        m_counter = 0;
    }
};

int main() {
    Accumulator acc;
    // they look more like functions now than classes
    std::cout << acc(1) << '\n'; // 1
    std::cout << acc(3) << '\n'; // 4

    Accumulator acc2;
    std::cout << acc2(10) << '\n'; // 10
    std::cout << acc2(20) << '\n'; // 30

    return 0;
}