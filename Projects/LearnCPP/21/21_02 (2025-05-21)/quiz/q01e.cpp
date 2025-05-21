// https://www.learncpp.com/cpp-tutorial/overloading-the-arithmetic-operators-using-friend-functions

/*
e) Extra credit: the fraction 2/4 is the same as 1/2, but 2/4 is not reduced to the lowest terms. We can reduce any given fraction to lowest terms by finding the greatest common divisor (GCD) between the numerator and denominator, and then dividing both the numerator and denominator by the GCD.

std::gcd() was added to the standard library in C++17 (in the <numeric> header).

If you’re on an older compiler, you can use this function to find the GCD:

```
#include <cmath> // for std::abs

int gcd(int a, int b) {
    return (b == 0) ? std::abs(a) : gcd(b, a % b);
}
```

Write a member function named reduce() that reduces your fraction. Make sure all fractions are properly reduced.

The following should compile:

```
#include <iostream>

int main()
{
    Fraction f1{2, 5};
    f1.print();

    Fraction f2{3, 8};
    f2.print();

    Fraction f3{ f1 * f2 };
    f3.print();

    Fraction f4{ f1 * 2 };
    f4.print();

    Fraction f5{ 2 * f2 };
    f5.print();

    Fraction f6{ Fraction{1, 2} * Fraction{2, 3} * Fraction{3, 4} };
    f6.print();

    Fraction f7{0, 6};
    f7.print();

    return 0;
}
```

And produce the result:
```
2/5
3/8
3/20
4/5
3/4
1/4
0/1
```

*/

#include <iostream>
#include <numeric>  // for std::gcd

class Fraction {
private:
    int m_numerator { 0 };
    int m_denominator { 1 };

public:
    explicit Fraction(int numerator, int denominator=1)
        : m_numerator { numerator }, m_denominator { denominator } {
        // We put reduce() in the constructor to ensure any fractions we make get reduced!
        // Since all of the overloaded operators create new Fractions, we can guarantee this will get called here
        reduce();
    }

    void reduce() {
        int gcd { std::gcd(m_numerator, m_denominator) };
        if (gcd) {  // Make sure we don't try to divide by 0
            m_numerator /= gcd;
            m_denominator /= gcd;
        }
    }

    friend Fraction operator*(const Fraction& f1, const Fraction& f2);
    friend Fraction operator*(const Fraction& f1, int value);
    friend Fraction operator*(int value, const Fraction& f1);

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

	Fraction f6{ Fraction { 1, 2 } * Fraction { 2, 3 } * Fraction { 3, 4 } };
	f6.print();

    Fraction f7 { 0, 6 };
	f7.print();

    return 0;
}