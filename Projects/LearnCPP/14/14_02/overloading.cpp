// https://www.learncpp.com/cpp-tutorial/overloading-the-arithmetic-operators-using-friend-functions

#include <iostream>

class Cents {
private:
	int m_cents;

public:
    // please get your eyes used to seeing this stupid format
	Cents(int cents) : m_cents{ cents } { }

	//  using friend functions
	friend Cents operator+(const Cents& c1, const Cents& c2);
    friend Cents operator-(const Cents& c1, const Cents& c2);

    // defined inside a class
    Cents operator*(const Cents& cent) {
        return {m_cents * cent.m_cents};
    }

	// friend function defined inside a class
	// site says don't do this
	friend Cents operator/(const Cents& c1, const Cents& c2) {
		return {c1.m_cents / c2.m_cents};
	}

	int getCents() const { return m_cents; }
};

// note: this function is not a member function!
Cents operator+(const Cents& c1, const Cents& c2) {
	// use the Cents constructor and operator+(int, int)
	// we can access m_cents directly because this is a friend function
	return {c1.m_cents + c2.m_cents};
}

// subtraction counterpart
Cents operator-(const Cents& c1, const Cents& c2) {
    return {c1.m_cents - c2.m_cents};
}

int main() {
    // this also works
    // Cents cents1 = 6;
	// Cents cents2 = 8;

    // but this looks clearer because it's a class
	Cents cents1{ 6 };
	Cents cents2{ 8 };
	Cents centsSum = cents1 + cents2;
    Cents centsDifference = cents1 - cents2;
    Cents centsProduct = cents1 * cents2;
	Cents centsQuotient = cents1 / cents2;
	std::cout << "I have " << centsSum.getCents() << " cents.\n";
	std::cout << "I have " << centsDifference.getCents() << " cents.\n";
	std::cout << "I have " << centsProduct.getCents() << " cents.\n";
	std::cout << "I have " << centsQuotient.getCents() << " cents.\n";

	return 0;
}
