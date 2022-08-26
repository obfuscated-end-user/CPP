// https://www.learncpp.com/cpp-tutorial/introduction-to-the-preprocessor/

#include <iostream>

int main() {
// #ifndef PRINT_BOB
#if !defined(PRINT_BOB) // this also works
    std::cout << "Bob\n";
#endif

    return 0;
}