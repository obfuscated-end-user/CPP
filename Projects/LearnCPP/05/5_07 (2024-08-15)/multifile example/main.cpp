// https://www.learncpp.com/cpp-tutorial/inline-functions-and-variables

#include "pi.h" // will include a copy of pi() here
#include <iostream>

double circumference(double radius);    // forward declaration

/* inline double pi() {
    return 3.14159;
} */

int main() {
    std::cout << pi() <<'\n';
    std::cout << circumference(2.0) <<'\n';

    return 0;
}