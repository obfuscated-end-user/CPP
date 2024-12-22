// https://www.learncpp.com/cpp-tutorial/ref-qualifiers

#include <iostream>
#include <string>
#include <string_view>

class Employee {
private:
    std::string m_name {};

public:
    Employee(std::string_view name) : m_name { name } {}

    const std::string& getName() const & {
        return m_name;  // & qualifier overloads function to match only lvalue implicit objects
    }

    const std::string& getName() const && {
        return m_name;  // && qualifier overloads function to match only rvalue implicit objects
    }

    // If the implicit object is a non-const rvalue, use std::move to try to move n_name
    std::string getName() && {
        return std::move(m_name);
    }
};

// createEmployee() returns an Employee by value (which means the returned value is an rvalue)
Employee createEmployee(std::string_view name) {
    Employee e { name };
    return e;
}

int main() {
    Employee joe { "Joe" };
    std::cout << joe.getName() << '\n'; // Joe is an lvalue, so this calls std::string& getName() & (returns a reference)

    std::cout << createEmployee("Frank").getName() << '\n'; // Frank is an rvalue, so this calls std::string getName() && (makes a copy)

    return 0;
}