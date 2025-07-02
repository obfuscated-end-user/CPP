// https://www.learncpp.com/cpp-tutorial/virtual-destructors-virtual-assignment-and-overriding-virtualization

#include <iostream>
#include <string_view>

class Base {
public:
	virtual ~Base() = default;

	virtual std::string_view getName() const {
		return "Base";
	}
};

class Derived : public Base {
public:
	virtual std::string_view getName() const {
		return "Derived";
	}
};

int main() {
	Derived derived {};
	const Base& base { derived };

	// Calls Base::getName() insteadof the virtualized Derived::getName()
	std::cout << base.Base::getName() << '\n';

	return 0;
}