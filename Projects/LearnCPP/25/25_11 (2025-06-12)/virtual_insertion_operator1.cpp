// https://www.learncpp.com/cpp-tutorial/printing-inherited-classes-using-operator

#include <iostream>

class Base {
public:
	// Here's our overloaded operator<<
	friend std::ostream& operator<<(std::ostream& out, const Base& b) {
		// Call virtual function identify() to get the string to be printed
		out << b.identify();
		return out;
	}

	// We'll rely on member function identify() to return the string to be printed
	// Because identify() is a normal member function, it can be virtualized
	virtual std::string identify() const {
		return "Base";
	}
};

class Derived : public Base {
public:
	// Here's our override identify() function to handle the Derived case
	std::string identify() const override {
		return "Derived";
	}
};

int main() {
	Base b {};
	std::cout << b << '\n';

	Derived d {};
	std::cout << d << '\n'; // note that this works even with no operator<< that explicitly handles Derived objects

	Base& bref { d };
	std::cout << bref << '\n';

	return 0;
}