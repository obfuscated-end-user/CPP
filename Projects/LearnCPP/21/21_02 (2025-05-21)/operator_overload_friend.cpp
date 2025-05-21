// https://www.learncpp.com/cpp-tutorial/overloading-the-arithmetic-operators-using-friend-functions

#include <iostream>

class Cents {
private:
    int m_cents {};

public:
    explicit Cents(int cents) : m_cents { cents } {}

    // add Cents + Cents using a friend function
    friend Cents operator+(const Cents& c1, const Cents& c2);

    // subtract Cents - Cents using a friend function
    friend Cents operator-(const Cents& c1, const Cents& c2);

    // This function is not considered a member of the class, even though the definition is inside the class
    friend Cents operator*(const Cents& c1, const Cents& c2) {
        // use the Cents constructor and operator*(int, int)
        // we can access m_cents directly because this is a friend function
        return Cents { c1.m_cents * c2.m_cents };
    }

    int getCents() const {
        return m_cents;
    }
};

// note: this function is not a member function!
Cents operator+(const Cents& c1, const Cents& c2) {
    // use the Cents constructor and operator+(int, int)
    // we can access m_cents directly because this is a friend function
    return Cents { c1.m_cents + c2.m_cents };
}

// note: this function is not a member function!
Cents operator-(const Cents& c1, const Cents& c2) {
    // use the Cents constructor and operator-(int, int)
    // we can access m_cents directly because this is a friend function
    return Cents { c1.m_cents - c2.m_cents };
}

int main() {
    Cents cents1 { 6 };
    Cents cents2 { 8 };
    Cents centSum { cents1 + cents2 };
    Cents centDifference { cents1 - cents2 };
    Cents centProduct { cents1 * cents2 };
    std::cout << "I have " << centSum.getCents() << " cents.\n";
    std::cout << "I have " << centDifference.getCents() << " cents.\n";
    std::cout << "I have " << centProduct.getCents() << " cents.\n";

    return 0;
}