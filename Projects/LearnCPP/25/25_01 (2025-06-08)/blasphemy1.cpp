// https://www.learncpp.com/cpp-tutorial/pointers-and-references-to-the-base-class-of-derived-objects

#include <array>
#include <iostream>
#include <string>
#include <string_view>

class Animal {
protected:
	std::string m_name;

	Animal(std::string_view name) : m_name { name } {}

	Animal(const Animal&) = delete;
	Animal& operator=(const Animal&) = delete;

public:
	std::string_view getName() const {
		return m_name;
	}

	std::string_view speak() const {
		return "???";
	}
};

class Cat : public Animal {
public:
	Cat(std::string_view name) : Animal { name } {}

	std::string_view speak() const {
		return "Woof";
	}
};

class Dog : public Animal {
public:
	Dog (std::string_view name) : Animal { name } {}

	std::string_view speak() const {
		return "Meow";
	}
};

int main() {
	const auto& cats { std::to_array<Cat>({ { "Fred" }, { "Misty" }, { "Zeke" } }) };
	const auto& dogs { std::to_array<Dog>({ { "Garbo" }, { "Pooky" }, { "Truffle" } }) };

	// Before C++20
	// const std::array<Cat, 3> cats{{ { "Fred" }, { "Misty" }, { "Zeke" } }};
	// const std::array<Dog, 3> dogs{{ { "Garbo" }, { "Pooky" }, { "Truffle" } }};

	for (const auto& cat : cats) {
		std::cout << cat.getName() << " says " << cat.speak() << '\n';
	}

	for (const auto& dog : dogs) {
		std::cout << dog.getName() << " says " << dog.speak() << '\n';
	}

	return 0;
}