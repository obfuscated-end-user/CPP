// https://www.learncpp.com/cpp-tutorial/pure-virtual-functions-abstract-base-classes-and-interface-classes

#include <iostream>
#include <string>
#include <string_view>

class Animal {  // This Animal is an abstract base class
protected:
	std::string m_name {};

public:
	Animal(std::string_view name) : m_name { name } {}

	const std::string& getName() const {
		return m_name;
	}

	virtual std::string_view speak() const = 0; // note that speak is now a pure virtual function

	virtual ~Animal() = default;
};

class Cat: public Animal {
public:
	Cat(std::string_view name) : Animal { name } {}

	std::string_view speak() const override {
		return "Meow";
	}
};

class Dog: public Animal {
public:
	Dog(std::string_view name) : Animal { name } {}

	std::string_view speak() const override {
		return "Woof";
	}
};

class Cow : public Animal {
public:
	Cow(std::string_view name) : Animal { name } {}
	
	std::string_view speak() const override {
		return "Moo";
	}
};

int main() {
	Cow cow { "Betsy" };
	std::cout << cow.getName() << " says " << cow.speak() << '\n';

	Animal& a { cow };
	std::cout << a.speak(); // resolves to Cow::speak(), prints "Moo"

	return 0;
}