// https://www.learncpp.com/cpp-tutorial/non-type-template-parameters

#include <iostream>

template <int N> // declare a non-type template parameter of type int named N
void print() {
    std::cout << N << '\n'; // use value of N here
}

int main() {
    print<5>(); // 5 is our non-type template argument

    return 0;
}

// N is used as a naming convention, much like T for template parameters