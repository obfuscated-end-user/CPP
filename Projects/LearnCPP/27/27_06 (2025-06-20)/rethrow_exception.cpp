// https://www.learncpp.com/cpp-tutorial/rethrowing-exceptions

#include <iostream>
class Base {
public:
	Base() {}

	virtual void print() {
		std::cout << "Base";
	}
};

class Derived : public Base {
public:
	Derived() {}

	void print() override {
		std::cout << "Derived";
	}
};

int main() {
	try {
		try {
			throw Derived {};
		} catch (Base& b) {
			std::cout << "Caught Base b, which is actually a ";
			b.print();
			std::cout << '\n';
			throw;	// note: We're now rethrowing the object here
		}
	} catch (Base& b) {
		std::cout << "Caught Base b, which is actually a ";
		b.print();
		std::cout << '\n';
	}

	return 0;
}