// https://www.learncpp.com/cpp-tutorial/constructor-member-initializer-lists

#include <iostream>

class A {
public:
    A(int x = 0) { std::cout << "A " << x << '\n'; }
};

class B {
private:
    A m_a {};
public:
    B(int y)
        // you're using a class here. so the format goes like: variable_name { arguments }
        : m_a{ y - 1 } // call A(int) constructor to initialize member m_a
    {
        std::cout << "B " << y << '\n';
    }
};

int main() {
    B b{ 5 };
    return 0;
}