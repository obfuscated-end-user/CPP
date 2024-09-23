// https://www.learncpp.com/cpp-tutorial/converting-constructors-and-the-explicit-keyword

#include <iostream>
#include <string>
#include <string_view>

class Employee {
private:
    std::string m_name {};

public:
    Employee(std::string_view name) : m_name { name } {}

    const std::string& getName() const {
        return m_name;
    }
};

void printEmployee(Employee e) {    // has an Employee parameter
    std::cout << e.getName();
}

int main() {
    // doesn't compile
    // only one user-defined conversion may be applue to perform an implicit conversion, and this example requires two
    // first, our C-style string literal has to be converted to a `std::string_view`
    // second, our `std::string_view` has to be converted into an Employee
    // printEmployee("Joe");   // we're supplying a string literal argument

    using namespace std::literals;
    printEmployee("Joe"sv); // now a std::string_view literal
    printEmployee(Employee{ "Joe" });

    return 0;
}