// https://www.learncpp.com/cpp-tutorial/increment-decrement-operators-and-side-effects/

#include <iostream>

int add(int x, int y) {
    return x + y;
}

int main() {
    int a { 5 };
    int b = ++a; // a is incremented to 6, a is evaluated to the value 6, and 6 is assigned to b
    std::cout << a << ' ' << b; // 6 6
    std::cout << '\n';

    int c { 5 };
    int d = c++; // c is incremented to 6, copy of original c is evaluated to the value 5, and 5 is assigned to d
    std::cout << c << ' ' << d; // 6 5
    std::cout << "\n\n";

    int x{ 5 };
    int y{ 5 };
    std::cout << x << ' ' << y << '\n'; // no changes

    // x and y are incremented/decremented before their values are sent to std::cout,
    // so we see their updated values reflected by std::cout.
    std::cout << ++x << ' ' << --y << '\n'; // prefix, 6 4
    std::cout << x << ' ' << y << '\n';

    // the copy of x and y (with the pre-incremented and pre-decremented values)
    // are what is sent to std::cout, so we don’t see the increment and decrement reflected here.
    // those changes don’t show up until the next line, when x and y are evaluated again.
    std::cout << x++ << ' ' << y-- << '\n'; // postfix, still at 6 4, because those are the temporary values
    std::cout << x << ' ' << y << '\n'; // now 7 3, these are the actual values of the variables, not the temporary ones

    int five{ 5 };
    int value{ add(five, ++five) }; // is this 5 + 6, or 6 + 6?
    // It depends on what order your compiler evaluates the function arguments in

    std::cout << value << '\n'; // value could be 11 or 12, depending on how the above line evaluates!
    // ^ 12 in my case
    return 0;
}