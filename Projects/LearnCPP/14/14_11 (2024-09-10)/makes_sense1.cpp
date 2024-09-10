// https://www.learncpp.com/cpp-tutorial/default-constructors-and-default-arguments

#include <iostream>

class Fraction {
private:
    int m_numerator { 0 };
    int m_denominator { 1 };

public:
    Fraction() = default;
    Fraction(int numerator, int denominator)
        : m_numerator { numerator }
        , m_denominator { denominator} {}

    void print() const {
        std::cout << "Fraction(" << m_numerator << ", " << m_denominator << ")\n";
    }
};

int main() {
    Fraction f1 { 3, 5 };
    f1.print();

    Fraction f2 {}; // will get Fraction 0/1
    f2.print();

    return 0;
}