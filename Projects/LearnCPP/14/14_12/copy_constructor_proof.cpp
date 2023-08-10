// https://www.learncpp.com/cpp-tutorial/the-copy-constructor

#include <cassert>
#include <iostream>

class Fraction {
private:
    int m_numerator;
    int m_denominator;

public:
    // Default constructor
    Fraction(int numerator=0, int denominator=1): m_numerator{numerator}, m_denominator{denominator} {
        assert(denominator != 0);
        std::cout << "Default constructor called\n";
    }

    // Copy constructor
    Fraction(const Fraction& fraction): m_numerator{fraction.m_numerator}, m_denominator{fraction.m_denominator} {
        // we can access the members of parameter fraction directly, because we're inside the Fraction class
        // no need to check for a denominator of 0 here since fraction must already be a valid Fraction
        std::cout << "Copy constructor called\n"; // just to prove it works
    }

    friend std::ostream& operator<<(std::ostream& out, const Fraction& f1);
};

std::ostream& operator<<(std::ostream& out, const Fraction& f1) {
	out << f1.m_numerator << '/' << f1.m_denominator;
	return out;
}

int main() {
	Fraction fiveThirds { 5, 3 };   // direct initialize a Fraction, calls Fraction(int, int) constructor
	Fraction fCopy { fiveThirds };  // direct initialize -- with Fraction copy constructor
	std::cout << fCopy << '\n';

    Fraction oneHalf { Fraction { 1, 2 } }; // anonymous objects still call the default constructor
}