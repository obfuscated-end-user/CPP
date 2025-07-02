// https://www.learncpp.com/cpp-tutorial/pure-virtual-functions-abstract-base-classes-and-interface-classes

#include <string_view>

class Base {
public:
	std::string_view sayHi() const {
		return "Hi";	// a normal non-virtual function
	}

	virtual std::string_view getName() const {
		return "Base";  // a normal virtual function
	}

	virtual int getValue() const = 0;	// a pure virtual function

	// int doSomething() = 0;  // Compile error: can not set non-virtual functions to 0
};

int main() {
	Base base {}; // We can't  instantiate an abstract base class, but for the sake of example, pretend this was allowed
	base.getValue();	// what would this do?

	return 0;
}