// https://www.learncpp.com/cpp-tutorial/struct-passing-and-miscellany/

#include <iostream>

struct Foo1 {
    short a{};
    short qq{}; // note: qq is defined here
    int b{};
    double c{};
};

struct Foo2 {
    short a{};
    int b{};
    double c{};
    short qq{}; // note: qq is defined here
};

int main() {
    std::cout << "The size of Foo1 is " << sizeof(Foo1) << '\n';
    std::cout << "The size of Foo2 is " << sizeof(Foo2) << '\n';

    return 0;
}