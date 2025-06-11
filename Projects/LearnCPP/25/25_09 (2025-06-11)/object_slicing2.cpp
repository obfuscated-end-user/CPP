// https://www.learncpp.com/cpp-tutorial/object-slicing

#include <iostream>
#include <string_view>

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

void printName1(const Base base) {   // note: base passed by value, not reference
    std::cout << "I am a " << base.getName() << '\n';
}

void printName2(const Base& base) {   // note: base now passed by reference
    std::cout << "I am a " << base.getName() << '\n';
}

int main() {
    Derived d { 5 };
    printName1(d);   // oops, didn't realize this was pass by value on the calling end
    printName2(d);

    return 0;
}