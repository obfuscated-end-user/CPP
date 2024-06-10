// https://www.learncpp.com/cpp-tutorial/function-overload-resolution-and-ambiguous-matches

#include <iostream>

void print(int x) {
    std::cout << x;
}

void print(double d) {
    std::cout << d;
}

int main() {
     print('a'); // char does not match int or double
     // print(5L); // long does not match int or double

    return 0;
}