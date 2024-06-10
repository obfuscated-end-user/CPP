// https://www.learncpp.com/cpp-tutorial/chapter-8-summary-and-quiz

/*
3b) Why won’t the following compile?

#include <iostream>

void print()
{
    std::cout << "void\n";
}

void print(int x=0)
{
    std::cout << "int " << x << '\n';
}

void print(double x)
{
    std::cout << "double " << x << '\n';
}

int main()
{
    print(5.0f);
    print();

    return 0;
}
*/

#include <iostream>

void print() {
    std::cout << "void\n";
}

void print(int x=0) {
    std::cout << "int " << x << '\n';
}

void print(double x) {
    std::cout << "double " << x << '\n';
}

int main() {
    print(5.0f);
    print();

    return 0;
}

// print is a void type, therefore it doesn't return anything

// Because parameters with default arguments aren’t counted for resolving overloaded functions, the compiler can’t tell whether the call to print() should resolve to print() or print(int x=0).