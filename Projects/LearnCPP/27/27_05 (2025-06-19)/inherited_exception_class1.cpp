// https://www.learncpp.com/cpp-tutorial/exceptions-classes-and-inheritance

#include <iostream>

class Base {
public:
	Base() {}
};

class Derived: public Base {
public:
	Derived() {}
};

int main() {
	try {
		throw Derived();
	} catch (const Base& base) {
		std::cerr << "caught Base";
	} catch (const Derived& derived) {
		std::cerr << "caught Derived";
	}

	return 0;
}