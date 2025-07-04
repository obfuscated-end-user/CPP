// https://www.learncpp.com/cpp-tutorial/adding-new-functionality-to-a-derived-class

#include <iostream>

class Base {
protected:
	int m_value {};

public:
	Base(int value) : m_value { value } {}

	void identify() const {
		std::cout << "I am a base\n";
	}
};

class Derived : public Base {
public:
	Derived(int value) : Base { value } {}

	int getValue() const {
		return m_value;
	}
};

int main() {
	Derived derived { 5 };
	std::cout << "derived has value " << derived.getValue() << '\n';

	Base base { 5 };
	// std::cout << "base has value " << base.getValue() << '\n';

	return 0;
}