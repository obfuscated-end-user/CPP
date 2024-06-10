// https://www.learncpp.com/cpp-tutorial/compile-time-constants-constant-expressions-and-constexpr

#include <iostream>

int main()
{
    constexpr double gravity { 9.8 }; // ok: 9.8 is a constant expression
    constexpr int sum { 4 + 5 };      // ok: 4 + 5 is a constant expression
    constexpr int something { sum };  // ok: sum is a constant expression

    std::cout << "Enter your age: ";
    int age{}; // vague, therefore not a constant expression
    std::cin >> age;

    // constexpr int myAge { age };      // compile error: age is not a constant expression

    return 0;
}
/*
Any variable that should not be modifiable after initialization and whose initializer is known at compile-time should be declared as constexpr.
Any variable that should not be modifiable after initialization and whose initializer is not known at compile-time should be declared as const.
*/