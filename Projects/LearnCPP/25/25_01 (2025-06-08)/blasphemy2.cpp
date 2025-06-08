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
    const Cat fred { "Fred" };
    const Cat misty { "Misty" };
    const Cat zeke { "Zeke" };

    const Dog garbo { "Garbo" };
    const Dog pooky { "Pooky" };
    const Dog truffle { "Truffle" };

    // Set up an array of pointers to animals, and set those pointers to our Cat and Dog objects
    const auto animals { std::to_array<const Animal*>({ &fred, &garbo, &misty, &pooky, &truffle, &zeke }) };

    // Before C++20, with the array size being explicitly specified
    // const std::array<const Animal*, 6> animals { &fred, &garbo, &misty, &pooky, &truffle, &zeke };

    for (const auto animal : animals) {
        std::cout << animal->getName() << " says " << animal->speak() << '\n';
    }
    return 0;
}