// https://www.learncpp.com/cpp-tutorial/virtual-functions

#include <iostream>
#include <string_view>

class Base {
public:
    virtual std::string_view getName() const {
        return "Base";  // note addition of virtual keyword
    }

    // Some modern compilers may give an error about having virtual functions and an accessible non-virtual destructor.
    virtual ~Base() = default;
};

class Derived : public Base {
public:
    virtual std::string_view getName() const {
        return "Derived";
    }
};

int main() {
    Derived derived {};
    Base& rBase { derived };
    std::cout << "rBase is a " << rBase.getName() << '\n';

    return 0;
}