// https://www.learncpp.com/cpp-tutorial/calling-inherited-functions-and-overriding-behavior

#include <iostream>

class Base {
private:
	void print() const {
		std::cout << "Base";
	}
};

class Derived : public Base {
public:
	void print() const {
		std::cout << "Derived";
	}
};

int main() {
	Derived derived {};
	derived.print();	// calls derived::print(), which is public

	return 0;
}