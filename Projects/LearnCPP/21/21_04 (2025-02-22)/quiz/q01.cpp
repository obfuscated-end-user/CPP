// https://www.learncpp.com/cpp-tutorial/overloading-the-io-operators

/*
Take the Fraction class below and add an overloaded operator<< and operator>> to it. Your operator>> should avoid partial extractions and fail if user inputs a denominator of 0. It should not reset the Fraction to default on failure.

The following program should compile:

```
int main()
{
	Fraction f1{};
	std::cout << "Enter fraction 1: ";
	std::cin >> f1;

	Fraction f2{};
	std::cout << "Enter fraction 2: ";
	std::cin >> f2;

	std::cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n'; // note: The result of f1 * f2 is an r-value

	return 0;
}
```

And produce the result:

```
Enter fraction 1: 2/3
Enter fraction 2: 3/8
2/3 * 3/8 is 1/4
```

Here’s the Fraction class:

```
#include <iostream>
#include <numeric> // for std::gcd

class Fraction
{
private:
	int m_numerator{};
	int m_denominator{};

public:
	Fraction(int numerator=0, int denominator=1):
		m_numerator{numerator}, m_denominator{denominator}
	{
		// We put reduce() in the constructor to ensure any new fractions we make get reduced!
		// Any fractions that are overwritten will need to be re-reduced
		reduce();
	}

	void reduce()
	{
		int gcd{ std::gcd(m_numerator, m_denominator) };
		if (gcd)
		{
			m_numerator /= gcd;
			m_denominator /= gcd;
		}
	}

	friend Fraction operator*(const Fraction& f1, const Fraction& f2);
	friend Fraction operator*(const Fraction& f1, int value);
	friend Fraction operator*(int value, const Fraction& f1);

	void print() const
	{
		std::cout << m_numerator << '/' << m_denominator << '\n';
	}
};

Fraction operator*(const Fraction& f1, const Fraction& f2)
{
	return Fraction { f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator };
}

Fraction operator*(const Fraction& f1, int value)
{
	return Fraction { f1.m_numerator * value, f1.m_denominator };
}

Fraction operator*(int value, const Fraction& f1)
{
	return Fraction { f1.m_numerator * value, f1.m_denominator };
}
```

If you’re on a pre-C++17 compiler, you can replace std::gcd with this function:

```
#include <cmath>

int gcd(int a, int b) {
    return (b == 0) ? std::abs(a) : gcd(b, a % b);
}
```
*/

#include <iostream>
#include <limits>
#include <numeric> // for std::gcd

class Fraction {
private:
    int m_numerator { 0 };
    int m_denominator { 1 };

public:
    Fraction(int numerator=0, int denominator=1) :
        m_numerator { numerator }, m_denominator { denominator } {
        // We put reduce() in the constructor to ensure any new fractions we make get reduced!
        // Any fractions that are overwritten will need to be re-reduced
        reduce();
    }

    void reduce() {
        int gcd { std::gcd(m_numerator, m_denominator) };
        if (gcd) {
            m_numerator /= gcd;
            m_denominator /= gcd;
        }
    }

    friend Fraction operator*(const Fraction& f1, const Fraction& f2);
    friend Fraction operator*(const Fraction& f1, int value);
    friend Fraction operator*(int value, const Fraction& f1);

    friend std::ostream& operator<<(std::ostream& out, const Fraction& f1);

    void print() const {
        std::cout << m_numerator << '/' << m_denominator << '\n';
    }
};

Fraction operator*(const Fraction& f1, const Fraction& f2) {
    return Fraction { f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator };
}

Fraction operator*(const Fraction& f1, int value) {
    return Fraction { f1.m_numerator * value, f1.m_denominator };
}

Fraction operator*(int value, const Fraction& f1) {
    return Fraction { f1 * value };
}

std::ostream& operator<<(std::ostream& out, const Fraction& f1) {
    return out << f1.m_numerator << '/' << f1.m_denominator;
}

std::istream& operator>>(std::istream& in, Fraction& f1) {
    int numerator {};
    char ignore {};
    int denominator {};

    in >> numerator >> ignore >> denominator;
    if (denominator == 0)                           // if our denominator is semantically invalid
        in.setstate(std::ios_base::failbit);        // set failure mode manually
    if (in)                                         // if we're not in failure mode
        f1 = Fraction { numerator, denominator };   // update our object to the extracted values

    return in;
}

int main() {
    Fraction f1 {};
    std::cout << "Enter fraction 1: ";
    std::cin >> f1;

    Fraction f2 {};
    std::cout << "Enter fraction 2: ";
    std::cin >> f2;

    std::cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n'; // note: The result of f1 * f2 is an r-value

    return 0;
}