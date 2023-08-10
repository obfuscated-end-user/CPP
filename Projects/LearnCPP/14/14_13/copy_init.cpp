// https://www.learncpp.com/cpp-tutorial/copy-initialization

#include <cassert>
#include <iostream>

class Fraction {
private:
    int m_numerator;
    int m_denominator;

public:
    // Default constructor
    Fraction(int numerator=0, int denominator=1): m_numerator(numerator), m_denominator(denominator) {
        assert(denominator != 0);
    }

    friend std::ostream& operator<<(std::ostream& out, const Fraction& f1);
};

std::ostream& operator<<(std::ostream& out, const Fraction& f1) {
	out << f1.m_numerator << '/' << f1.m_denominator;
	return out;
}

int main() {
    // Fraction six(Fraction(6));
    Fraction six = Fraction(6); // 6/1
    std::cout << six;
    return 0;
}