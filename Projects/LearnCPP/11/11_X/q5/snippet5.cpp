// https://www.learncpp.com/cpp-tutorial/chapter-11-comprehensive-quiz

/*
Question #5

What’s wrong with each of these snippets, and how would you fix it?

e)

int main()
{
    double d{ 5.5 };
    int* ptr{ &d };
    std::cout << ptr << '\n';

    return 0;
}
*/

#include <iostream>

int main() {
    double d{ 5.5 };
    int* ptr{ &d }; // can't reference int pointer to an address that holds a double type
    std::cout << ptr << '\n';

    return 0;
}

// You can’t make an int pointer point at a non-int variable. ptr should be of type double*.