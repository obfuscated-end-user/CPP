// https://www.learncpp.com/cpp-tutorial/object-slicing

#include <functional>   // for std::reference_wrapper
#include <iostream>
#include <string_view>
#include <vector>

class Base {
protected:
    int m_value {};

public:
    Base(int value) : m_value { value } {}

    virtual ~Base() = default;

    virtual std::string_view getName() const {
        return "Base";
    }

    int getValue() const {
        return m_value;
    }
};

class Derived : public Base {
public:
    Derived(int value) : Base { value } {}

    std::string_view getName() const override {
        return "Derived";
    }
};

int main() {
    std::vector<std::reference_wrapper<Base>> v {}; // a vector of reassignable references to Base
    
    Base b { 5 };   // b and d can't be anonymous objects
    Derived d { 6 };

    v.push_back(b); // add a Base object to our vector
    v.push_back(d); // add a Derived object to our vector

    // Print out all of the elements in our vector
    // we use .get() to get our element out of the std::reference_wrapper
    for (const auto& element : v)   // element has type std::reference_wrapper<Base>&
        std::cout << "I am a " << element.get().getName() << " with value " << element.get().getValue() << '\n';
    
    return 0;
}