// https://www.learncpp.com/cpp-tutorial/overloading-the-arithmetic-operators-using-friend-functions

/*
c) Why does the program continue to work correctly if we make the constructor non-explicit and remove the operators for integer multiplication from the previous solution?

```
// Remove explicit from constructor
	Fraction(int numerator, int denominator=1)
		: m_numerator{numerator}, m_denominator{denominator}
	{
	}

// We can remove these operators, and the program continues to work
Fraction operator*(const Fraction& f1, int value);
Fraction operator*(int value, const Fraction& f1);
```

*/

#include <iostream>

class Fraction {
private:
	int m_numerator { 0 };
	int m_denominator { 1 };

public:
	Fraction(int numerator, int denominator=1)
		: m_numerator { numerator }, m_denominator { denominator } {}

	friend Fraction operator*(const Fraction& f1, const Fraction& f2);

	void print() const {
		std::cout << m_numerator << '/' << m_denominator << '\n';
	}
};

Fraction operator*(const Fraction& f1, const Fraction& f2) {
	return Fraction { f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator };
}

int main() {
	Fraction f1 { 2, 5 };
	f1.print();

	Fraction f2 { 3, 8 };
	f2.print();

	Fraction f3 { f1 * f2 };
	f3.print();

	Fraction f4 { f1 * 2 };
	f4.print();

	Fraction f5 { 2 * f2 };
	f5.print();

	Fraction f6 { Fraction { 1, 2 } * Fraction { 2, 3 } * Fraction { 3, 4 } };
	f6.print();

	return 0;
}