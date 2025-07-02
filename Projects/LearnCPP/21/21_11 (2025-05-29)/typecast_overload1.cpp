// https://www.learncpp.com/cpp-tutorial/overloading-typecasts

#include <iostream>

void printInt(int value) {
	std::cout << value;
}

class Cents {
private:
	int m_cents {};

public:
	Cents(int cents=0) : m_cents { cents } {}

	// Overloaded int cast
	operator int() const {
		return m_cents;
	}

	int getCents() const {
		return m_cents;
	}

	void setCents(int cents) {
		m_cents = cents;
	}
};

int main() {
	Cents cents { 7 };
	printInt(cents);	// print 7

	std::cout << '\n';
	std::cout << static_cast<int>(cents);

	return 0;
}