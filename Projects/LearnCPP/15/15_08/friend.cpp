// https://www.learncpp.com/cpp-tutorial/friend-non-member-functions

#include <iostream>

class Accumulator {
private:
    int m_value { 0 };
public:
    void add(int value) {
        m_value += value;
    }

    // Here is the friend declaration thaat makes non-member function void print(const Accumulator& accumulator) a friend of Accumulator
    friend void print1(const Accumulator& accumulator);

    // Friend functions defined inside a class are non-member functions
    friend void print2(const Accumulator& accumulator) {
        // Because print() is a friend of Accumulator
        // it can access the private members of Accumulator
        std::cout << accumulator.m_value;
    }
};

void print1(const Accumulator& accumulator) {
    // Because print() is a friend of Accumulator
    // it can access the private members of Accumulator
    std::cout << accumulator.m_value;
}

int main() {
    Accumulator acc {};
    acc.add(5); // add 5 to the accumulator

    print1(acc); // call the print1() non-member function
    print2(acc); // call the print2() non-member function

    return 0;
}