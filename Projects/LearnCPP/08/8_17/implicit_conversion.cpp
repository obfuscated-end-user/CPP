// https://www.learncpp.com/cpp-tutorial/non-type-template-parameters

#include <iostream>

template <int N> // int non-type template parameter
void print() {
    std::cout << N << '\n';
}

int main() {
    print<5>();   // no conversion necessary
    print<'c'>(); // 'c' converted to type int, prints 99

    return 0;
}