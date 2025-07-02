// https://www.learncpp.com/cpp-tutorial/object-slicing

#include <iostream>
#include <string_view>
#include <vector>

class Base {
protected:
	int m_value {};

public:
	Base(int value) : m_value { value } {}

	virtual ~Base() = default;

	virtual std::string_view getName() const {
		return "Base";
	}

	int getValue() const {
		return m_value;
	}
};

class Derived : public Base {
public:
	Derived(int value) : Base { value } {}

	std::string_view getName() const override {
		return "Derived";
	}
};

int main() {
	Derived d1 { 5 };
	Derived d2 { 6 };
	Base& b { d2 };

	b = d1; // this line is problematic

	return 0;
}