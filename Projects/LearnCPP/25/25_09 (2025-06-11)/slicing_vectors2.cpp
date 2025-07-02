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
	std::vector<Base*> v {};
	
	Base b { 5 };	// b and d can't be anonymous objects
	Derived d { 6 };

	v.push_back(&b);	// add a Base object to our vector
	v.push_back(&d);	// add a Derived object to our vector

	// Print out all of the elements in our vector
	for (const auto* element : v)
		std::cout << "I am a " << element->getName() << " with value " << element->getValue() << '\n';
	
	return 0;
}