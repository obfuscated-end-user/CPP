// https://www.learncpp.com/cpp-tutorial/function-try-blocks

#include <iostream>

class A {
private:
    int m_x;
public:
    A(int x) : m_x { x } {
        if (x <= 0)
            throw 1;    // Exception thrown here
    }
};

class B : public A {
public:
    B(int x) : A { x } {    // A initialized in member initializer list of B
        // What happens if creation of A fails and we want to handle it here?
    }
};

int main() {
    try {
        B b { 0 };
    } catch (int) {
        std::cout << "Oops\n";
    }

    return 0;
}