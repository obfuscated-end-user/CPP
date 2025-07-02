// https://www.learncpp.com/cpp-tutorial/overloading-operators-using-normal-functions

#ifndef CENTS_H
#define CENTS_H

class Cents {
private:
	int m_cents {};

public:
	Cents(int cents) : m_cents { cents } {}

	int getCents() const {
		return m_cents;
	}
};

// Need to explicitly provide prototype for operator+ so uses of operator+ in other files know this overload exists
Cents operator+(const Cents& c1, const Cents& c2);

#endif