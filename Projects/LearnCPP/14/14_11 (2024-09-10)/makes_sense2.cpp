// https://www.learncpp.com/cpp-tutorial/default-constructors-and-default-arguments

#include <iostream>
#include <string>
#include <string_view>

class Employee {
private:
    std::string m_name {};
    int m_id {};

public:
    Employee(std::string_view name, int id)
        : m_name { name }
        , m_id { id } {}

    void print() const {
        std::cout << "Employee(" << m_name << ", " << m_id << ")\n";
    }
};

int main() {
    Employee e1 { "Joe", 1 };
    e1.print();

    // For a class representing an employeem it doesn't make sense to allow creation of employees with no name.
    Employee e2 {}; // compile error: no matching constructor
    e2.print();

    return 0;
}
