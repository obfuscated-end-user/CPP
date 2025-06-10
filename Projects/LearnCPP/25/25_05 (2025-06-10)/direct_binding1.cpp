// https://www.learncpp.com/cpp-tutorial/early-binding-and-late-binding

#include <iostream>

struct Foo {
    void printValue(int value) {
        std::cout << value;
    }
};

void printValue(int value) {
    std::cout << value;
}

int main() {
    printValue(5);   // direct function call to printValue(int)

    Foo f {};
    f.printValue(5); // direct function call to Foo::printValue(int)
    return 0;
}