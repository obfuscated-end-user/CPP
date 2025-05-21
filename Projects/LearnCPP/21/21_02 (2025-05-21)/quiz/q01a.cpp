// https://www.learncpp.com/cpp-tutorial/overloading-the-arithmetic-operators-using-friend-functions

/*
a) Write a class named Fraction that has an integer numerator and denominator member. Write a print() function that prints out the fraction.

The following code should compile:

```
#include <iostream>

int main()
{
    Fraction f1{ 1, 4 };
    f1.print();

    Fraction f2{ 1, 2 };
    f2.print();

    return 0;
}
```

This should print:

```
1/4
1/2
```

*/

#include <iostream>

class Fraction {
private:
    int m_numerator { 0 };
    int m_denominator { 0 };

public:
    explicit Fraction(int numerator, int denominator=1)
        : m_numerator { numerator }, m_denominator { denominator } {}

    void print() const {
        std::cout << m_numerator << '/' << m_denominator << '\n';
    }
};

int main() {
    Fraction f1 { 1, 4 };
    f1.print();

    Fraction f2 { 1, 2 };
    f2.print();

    return 0;
}