// https://www.learncpp.com/cpp-tutorial/c-style-string-symbolic-constants

#include <iostream>

int main() {

    char c { 'Q' };
    std::cout << &c;

    const char* ptr { "Bert" };
    std::cout << '\n' << ptr << '\n';                               // print ptr as C-style string
    std::cout << static_cast<const void*> (ptr) << '\n';    // print address held by ptr

    return 0;
}