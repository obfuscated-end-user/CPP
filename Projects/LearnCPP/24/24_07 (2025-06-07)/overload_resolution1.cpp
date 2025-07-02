// https://www.learncpp.com/cpp-tutorial/calling-inherited-functions-and-overriding-behavior

#include <iostream>

class Base {
public:
	void print(int) {
		std::cout << "Base::print(int)\n";
	}

	void print(double) {
		std::cout << "Base::print(double)\n";
	}
};

class Derived : public Base {
public:
};

int main() {
	Derived d {};
	d.print(5); // calls Base::print(int)

	return 0;
}