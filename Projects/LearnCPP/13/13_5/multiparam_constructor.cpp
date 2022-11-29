// https://www.learncpp.com/cpp-tutorial/constructors/

#include <cassert>

class Fraction {
private:
    int m_numerator {};
    int m_denominator {};

public:
    Fraction() {   // defualt constructor
        m_numerator = 0;
        m_denominator = 1;
    }

    // Constructor with two parameters, one parameter having a default value

    Fraction(int numerator, int denominator = 1) {
        assert(denominator != 0);
        m_numerator = numerator;
        m_denominator = denominator;
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
    // tutorial says prefer list initialization/brace initialization
    Fraction fiveThirds{ 5, 3 };   // List initialization, calls Fraction(int, int)
    Fraction threeQuarters(3, 4);   // Direct initialization, also calls Fraction(int, int)

    // also allowed
    Fraction six{ 6 };  // calls Fraction(int, int) constructor, second parameter uses default value of 1

    // copy initialization. tutorial says avoid this shit like the plague.
    Fraction six = Fraction{ 6 };   // Copy initialize a Fraction, will call Fraction(6, 1)
    Fraction seven = 7; // Copy initialize a Fraction. The compiler will try to find a way to convert 7 to a Fraction, which will invoke the Fraction(7, 1) constructor.
}