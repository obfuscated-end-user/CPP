// https://www.learncpp.com/cpp-tutorial/overloading-the-arithmetic-operators-using-friend-functions

#include <iostream>

class Cents {
private:
    int m_cents {};

public:
    explicit Cents(int cents) : m_cents{ cents } {}

    // add Cents + int using a friend function
    friend Cents operator+(const Cents& c1, int value);

    // add int + Cents using a friend function
    friend Cents operator+(int value, const Cents& c1);

    int getCents() const { return m_cents; }
};

// note: this function is not a member function!
Cents operator+(const Cents& c1, int value) {
    // use the Cents constructor and operator+(int, int)
    // we can access m_cents directly because this is a friend function
    return Cents { c1.m_cents + value };
}

// note: this function is not a member function!
Cents operator+(int value, const Cents& c1) {
    // use the Cents constructor and operator+(int, int)
    // we can access m_cents directly because this is a friend function
    return Cents { c1.m_cents + value };
}

int main() {
    Cents c1 { Cents { 4 } + 6 };
    Cents c2 { 6 + Cents { 4 } };

    std::cout << "I have " << c1.getCents() << " cents.\n";
    std::cout << "I have " << c2.getCents() << " cents.\n";

    return 0;
}