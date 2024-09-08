// https://www.learncpp.com/cpp-tutorial/member-functions-returning-references-to-data-members

#include <iostream>

class Foo {
private:
    int m_value { 4 };  // private member

public:
    int& value() {
        return m_value; // returns a non-const reference (don't do this)
    }
};

int main() {
    Foo f {};               // f.m_value is initialized to default value 4
    f.value() = 5;          // The equivalent of m_value = 5
    std::cout << f.value(); // prints 5

    return 0;
}