// https://www.learncpp.com/cpp-tutorial/chapter-8-summary-and-quiz/

/*
3a) What is the output of this program and why?

#include <iostream>

void print(int x)
{
    std::cout << "int " << x << '\n';
}

void print(double x)
{
    std::cout << "double " << x << '\n';
}

int main()
{
    short s { 5 };
    print(s);

    return 0;
}
*/

#include <iostream>

void print(int x) {
    std::cout << "int " << x << '\n';
}

void print(double x) {
    std::cout << "double " << x << '\n';
}

int main() {
    short s { 5 };
    print(s);
    return 0;
}

// because short is converted into an integer
// short has a smaller size than both int and double, but since int is smaller than double, it is therefore the nearest possible choice
// what in the everliving fuck was that explanation you absolute fucking retard.