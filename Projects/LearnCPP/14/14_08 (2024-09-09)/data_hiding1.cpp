// https://www.learncpp.com/cpp-tutorial/the-benefits-of-data-hiding-encapsulation

#include <iostream>
#include <string>
#include <string_view>

class Employee {
    std::string m_name {};
    // char m_firstInitial {};

public:
    void setName(std::string_view name) {
        m_name = name;
        // m_firstInitial = name.front();  // use std::string::front() to get first letter of `name`
    }

    // use std::string::front() to get first letter of `m_name`
    char firstInitial() const {
        return m_name.front();
    }

    void print() const {
        // std::cout << "Employee " << m_name << " has first initial " << m_firstInitial << '\n';
        std::cout << "Employee " << m_name << " has first initial " << firstInitial() << '\n';
    }
};

int main() {
    Employee e {};
    e.setName("John");
    e.print();

    e.setName("Mark");
    e.print();

    return 0;
}