// https://www.learncpp.com/cpp-tutorial/overlapping-and-delegating-constructors

#include <iostream>

class Foo {
private:
    int m_a { 5 };
    int m_b { 6 };


public:
    Foo() {}

    Foo(int a, int b) : m_a{ a }, m_b{ b } {
    }

    void print() {
        std::cout << m_a << ' ' << m_b << '\n';
    }

    void reset() {
        // consider this a bit of magic for now
        *this = Foo(); // create new Foo object, then use assignment to overwrite our implicit object
        // *this references this object. making it equal to Foo() means override the current object's values witht the defaults above. what did you just write here?
    }
};

int main() {
    Foo a{ 1, 2 };
    a.reset();

    a.print();

    return 0;
}

// reset() meaning to reset the variables m_a and m_b to their original default state (5 and 6)