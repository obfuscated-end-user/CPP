#include <iostream>

class Fraction {
private:
    // the brackets are the fucking initializers
    int m_numerator {};
    int m_denominator {};

public:
    Fraction() {    // default constructor
        m_numerator = 0;
        m_denominator = 1;
    }

    int getNumerator() {
        return m_numerator;
    }
    int getDenominator() {
        return m_denominator;
    }
    double getValue() {
        return static_cast<double>(m_numerator) / m_denominator;
    }
};

int main() {
    // aka "value initialization", the fucking bracket notation
    Fraction frac{};    // calls Fraction() default constructor
    std::cout << frac.getNumerator() << '/' << frac.getDenominator() << '\n';

    return 0;
}

// ran this and got 69/0