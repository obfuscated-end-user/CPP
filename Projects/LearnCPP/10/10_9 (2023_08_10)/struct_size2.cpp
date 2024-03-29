// https://www.learncpp.com/cpp-tutorial/struct-miscellany

#include <iostream>

struct Foo1 {
    short a; // will have 2 bytes of padding after a
    int b;
    short c; // will have 2 bytes of padding after c
};

struct Foo2 {
    int b;
    short a;
    short c;
};

int main() {
    std::cout << sizeof(Foo1) << '\n'; // 12
    std::cout << sizeof(Foo2) << '\n'; // 8

    return 0;
}