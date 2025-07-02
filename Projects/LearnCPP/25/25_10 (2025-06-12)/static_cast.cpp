// https://www.learncpp.com/cpp-tutorial/dynamic-casting

#include <iostream>
#include <string>
#include <string_view>

// Class identifier
enum class ClassID {
	base,
	derived
	// Others can be added here later
};

class Base {
protected:
	int m_value {};

public:
	Base(int value) : m_value { value } {}

	virtual ~Base() = default;

	virtual ClassID getClassID() const {
		return ClassID::base;
	}
};

class Derived : public Base {
protected:
	std::string m_name {};

public:
	Derived(int value, std::string_view name)
		: Base { value }, m_name { name } {}

	const std::string& getName() const {
		return m_name;
	}

	ClassID getClassID() const override {
		return ClassID::derived;
	}
};

Base* getObject(bool bReturnDerived) {
	if (bReturnDerived)
		return new Derived { 1, "Apple" };
	else
		return new Base { 2 };
}

int main() {
	Base* b { getObject(true) };

	if (b->getClassID() == ClassID::derived) {
		// We already proved b is pointing to a Derived object, so this should always succeed
		Derived* d { static_cast<Derived*>(b) };
		std::cout << "The name of the Derived is: " << d->getName() << '\n';
	}

	delete b;

	return 0;
}