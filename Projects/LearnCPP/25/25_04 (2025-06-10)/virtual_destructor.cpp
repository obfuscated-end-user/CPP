// https://www.learncpp.com/cpp-tutorial/virtual-destructors-virtual-assignment-and-overriding-virtualization

#include <iostream>

class Base {
public:
	virtual ~Base() {	// note: virtual
		std::cout << "Calling ~Base()";
	}
};

class Derived : public Base {
private:
	int* m_array {};

public:
	Derived(int length) : m_array { new int[length] } {}

	virtual ~Derived() {	// note: virtual
		std::cout << "Calling ~Derived()\n";
		delete[] m_array;
	}
};

int main() {
	Derived* derived { new Derived(5) };
	Base* base { derived };

	delete base;

	return 0;
}