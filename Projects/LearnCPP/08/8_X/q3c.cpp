// https://www.learncpp.com/cpp-tutorial/chapter-8-summary-and-quiz/

/*
3c) Why won’t the following compile?

#include <iostream>

void print(long x)
{
    std::cout << "long " << x << '\n';
}

void print(double x)
{
    std::cout << "double " << x << '\n';
}

int main()
{
    print(5);

    return 0;
}
*/

#include <iostream>

void print(long x) {
    std::cout << "long " << x << '\n';
}

void print(double x) {
    std::cout << "double " << x << '\n';
}

int main() {
    print(5);

    return 0;
}

// the args can be applied to both overloads, therefore making the call ambiguous