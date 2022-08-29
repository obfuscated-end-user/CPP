// https://www.learncpp.com/cpp-tutorial/chapter-11-comprehensive-quiz/

/*
Question #5

What’s wrong with each of these snippets, and how would you fix it?

b)

int main()
{
    int x{ 5 };
    int y{ 7 };

    const int* ptr{ &x };
    std::cout << *ptr << '\n';
    *ptr = 6;
    std::cout << *ptr << '\n';
    ptr = &y;
    std::cout << *ptr << '\n';

    return 0;
}
*/

#include <iostream>

int main() {
    int x{ 5 };
    int y{ 7 };

    const int* ptr{ &x };
    std::cout << *ptr << '\n';
    *ptr = 6;   // you can't assign a new variable to a c-style string? also, "const int"
    std::cout << *ptr << '\n';
    ptr = &y;
    std::cout << *ptr << '\n';

    return 0;
}

// ptr is a pointer to a const int. You can’t assign the value 6 to it. You can fix this by making ptr non-const.