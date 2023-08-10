// https://www.learncpp.com/cpp-tutorial/overloading-unary-operators

#include <iostream>

class Cents {
private:
    int m_cents;

public:
    Cents(int cents): m_cents{cents} {}

    Cents operator-() const;

    int getCents() const { return m_cents; }
};

// Note that there’s no confusion between the negative operator- and the minus operator- since they have a different number of parameters.
Cents Cents::operator-() const {
    return -m_cents; // since return type is a Cents, this does an implicit conversion from int to Cents using the Cents(int) constructor
}

int main() {
    const Cents nickle{ 5 };
    std::cout << "A nickle of debt is worth " << (-nickle).getCents() << " cents\n";

    return 0;
}