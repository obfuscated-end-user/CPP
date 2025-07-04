// https://www.learncpp.com/cpp-tutorial/the-virtual-table

#include <iostream>
#include <string_view>

class Base {
public:
	std::string_view getName() const {	// not virtual
		return "Base";
	}

	virtual std::string_view getNameVirtual() const {	// virtual
		return "Base";
	}
};

class Derived: public Base {
public:
	std::string_view getName() const {
		return "Derived";
	}

	virtual std::string_view getNameVirtual() const override {
		return "Derived";
	}
};

int main() {
	Derived derived {};
	Base& base { derived };

	std::cout << "base has static type " << base.getName() << '\n';
	std::cout << "base has dynamic type " << base.getNameVirtual() << '\n';

	return 0;
}