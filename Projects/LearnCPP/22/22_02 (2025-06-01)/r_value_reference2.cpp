// https://www.learncpp.com/cpp-tutorial/rvalue-references

#include <iostream>

class Fraction {
private:
	int m_numerator { 0 };
	int m_denominator { 1 };

public:
	Fraction(int numerator=0, int denominator=1)
		: m_numerator { numerator }, m_denominator { denominator } {}

	friend std::ostream& operator<<(std::ostream& out, const Fraction& f1) {
		out << f1.m_numerator << '/' << f1.m_denominator;
		return out;
	}
};

int main() {
	auto&& rref { Fraction { 3, 5 } };  // r-value reference to temporary Fraction

	// f1 of operator<< binds to the temporary, no copies are created.
	std::cout << rref << '\n';

	return 0;
}	// rref (and the temporary Fraction) goes out of scope here