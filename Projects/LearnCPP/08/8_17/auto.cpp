// https://www.learncpp.com/cpp-tutorial/non-type-template-parameters

#include <iostream>

template <auto N> // deduce non-type template parameter from template argument
void print() {
    std::cout << N << '\n';
}

int main()
{
    print<5>();   // N deduced as int `5`
    print<'c'>(); // N deduced as char `c`

    return 0;
}