// https://www.learncpp.com/cpp-tutorial/calling-inherited-functions-and-overriding-behavior

#include <iostream>

class Base {
public:
	Base() {}

	void identify() const {
		std::cout << "Base::identify()\n";
	}
};

class Derived : public Base {
public:
	Derived() {}

	void identify() const {
		std::cout << "Derived::identify()\n";
	}
};

int main() {
	Base base {};
	base.identify();

	Derived derived {};
	derived.identify();

	return 0;
}