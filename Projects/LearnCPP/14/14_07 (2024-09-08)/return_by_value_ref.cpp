// https://www.learncpp.com/cpp-tutorial/member-functions-returning-references-to-data-members

#include <iostream>
#include <string>

class Employee {
    std::string m_name {};

public:
    void setName(std::string_view name) {
        m_name = name;
    }

    const std::string& getName() const {
        return m_name;  // getter returns by const reference
    }

    // using an auto return obscures the return type of the getter from a documentation perspective
    /* const auto& getName() const {
        return m_name;  // uses `auto` to deduce return type from m_name
    } */
};

int main() {
    Employee joe {};            // joe exists until end of function
    joe.setName("Joe");

    std::cout << joe.getName(); // returns joe.m_name by reference

    return 0;
}