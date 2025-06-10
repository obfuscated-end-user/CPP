// https://www.learncpp.com/cpp-tutorial/pure-virtual-functions-abstract-base-classes-and-interface-classes

#include <string>
#include <string_view>

class Animal {
protected:
    std::string m_name {};

public:
    Animal(std::string_view name) : m_name { name } {}

    const std::string& getName() {
        return m_name;
    }

    virtual std::string_view speak() const = 0; // The = 0 means this function is pure virtual

    virtual ~Animal() = default;
};

std::string_view Animal::speak() const {    // even though it has a definition
    return "buzz";
}