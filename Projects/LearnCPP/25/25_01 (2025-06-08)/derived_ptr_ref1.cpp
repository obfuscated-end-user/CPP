// https://www.learncpp.com/cpp-tutorial/pointers-and-references-to-the-base-class-of-derived-objects

#include <iostream>
#include <string_view>

class Base {
protected:
	int m_value {};

public:
	Base(int value) : m_value { value } {}

	std::string_view getName() const {
		return "Base";
	}

	int getValue() const {
		return m_value;
	}
};

class Derived: public Base {
public:
	Derived(int value) : Base { value } {}

	std::string_view getName() const {
		return "Derived";
	}

	int getValueDoubled() const {
		return m_value * 2;
	}
};

int main() {
	Derived derived { 5 };
	std::cout << "derived is a " << derived.getName() << " and has value " << derived.getValue() << '\n';

	Derived& rDerived { derived };
	std::cout << "rDerived is a " << rDerived.getName() << " and has value " << rDerived.getValue() << '\n';

	Derived* pDerived { &derived };
	std::cout << "pDerived is a " << pDerived->getName() << " and has value " << pDerived->getValue() << '\n';

	std::cout << '\n';

	// These are both legal!
	Base& rBase { derived };	// rBase is an lvalue reference (not an rvalue reference)
	Base* pBase { &derived };

	std::cout << "derived is a " << derived.getName() << " and has value " << derived.getValue() << '\n';
	std::cout << "rBase is a " << rBase.getName() << " and has value " << rBase.getValue() << '\n';
	std::cout << "pBase is a " << pBase->getName() << " and has value " << pBase->getValue() << '\n';

	return 0;
}