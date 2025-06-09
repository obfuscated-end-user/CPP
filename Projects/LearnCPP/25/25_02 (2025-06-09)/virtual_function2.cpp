// https://www.learncpp.com/cpp-tutorial/virtual-functions

#include <iostream>
#include <string_view>

class A {
public:
    virtual std::string_view getName() const {
        return "A";
    }
};

class B : public A {
public:
    virtual std::string_view getName() const {
        return "B";
    }
};

class C : public B {
public:
    virtual std::string_view getName() const {
        return "C";
    }
};

class D : public C {
public:
    virtual std::string_view getName() const {
        return "D";
    }
};

int main() {
    C c {};
    A& rBase { c };
    std::cout << "rBase is a " << rBase.getName() << '\n';

    std::cout << c.getName() << '\n';   // will always call C::getName

    A a { c };  // copies the A portion of c into a (don't do this)
    std::cout << a.getName() << '\n';   // will always call A::getName

    return 0;
}