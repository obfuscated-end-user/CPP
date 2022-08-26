// https://www.learncpp.com/cpp-tutorial/chapter-8-summary-and-quiz/

/*
What is the output of this program and why?

#include <iostream>

template <typename T>
int count(T) // This is the same as int count(T x), except we're not giving the parameter a name since we don't use the parameter
{
    static int c { 0 };
    return ++c;
}

int main()
{
    std::cout << count(1);
    std::cout << count(1);
    std::cout << count(2.3);
    std::cout << count<double>(1);

    return 0;
}
*/

#include <iostream>

template <typename T>
int count(T) { // This is the same as int count(T x), except we're not giving the parameter a name since we don't use the parameter
    static int c { 0 };
    return ++c;
}

int main() {
    std::cout << count(1);
    std::cout << count(1);
    std::cout << count(2.3);
    std::cout << count<double>(1);

    return 0;
}

/*
When count(1) is called, the compiler will instantiate the function count<int>(int) and call it. This will return 1.
When count(1) is called again, the compiler will see that count<int>(int) already exists, and call it again. This will return 2.
When count(2.3) is called, the compiler will instantiate the function with prototype count<double>(double) and call it. This is a new function with its own static c variable, so this will return 1.
When count<double>(1) is called, the compiler will see that we’re explicitly requesting the double version of count(). This function already exists due to the prior statement, so count<double>(double) will be called and the intargument will be implicitly converted to a double. This function will return 2.
*/