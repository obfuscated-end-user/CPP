#include <iostream>

class Fraction {
private:
    // removed initializers
    int m_numerator;
    int m_denominator;

public:
    // removed default construtor
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
    Fraction frac; 
    // frac is uninitialzed, accessing its members causes undefined behavior
    std::cout << frac.getNumerator() << '/' << frac.getDenominator() << '\n';

    return 0;
}