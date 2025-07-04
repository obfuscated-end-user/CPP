// https://www.learncpp.com/cpp-tutorial/virtual-functions

#include <iostream>
#include <string>
#include <string_view>

class Animal {
protected:
	std::string m_name {};

	// We're making this constructor protected because
	// we don't want people creating Animal objects directly,
	// but we still want derived classes to be able to use it.
	Animal(std::string_view name) : m_name { name } {}

public:
	const std::string& getName() const {
		return m_name;
	}

	virtual std::string_view speak() const {
		return "???";
	}
};

class Cat : public Animal {
public:
	Cat(std::string_view name) : Animal { name } {}

	virtual std::string_view speak() const {
		return "Meow";
	}
};

class Dog : public Animal {
public:
	Dog(std::string_view name) : Animal { name } {}

	virtual std::string_view speak() const {
		return "Woof";
	}
};

void report(const Animal& animal) {
	std::cout << animal.getName() << " says " << animal.speak() << '\n';
}

int main() {
	Cat cat { "Fred" };
	Dog dog { "Garbo" };

	report(cat);
	report(dog);

	return 0;
}