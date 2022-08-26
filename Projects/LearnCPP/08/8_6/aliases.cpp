// https://www.learncpp.com/cpp-tutorial/typedefs-and-type-aliases/

#include <iostream>
#include <typeinfo>
#include <type_traits>

int main() {
    // std::cout << '\n';

    using distance_t = double; // define distance_t as an alias for type double
    distance_t milesToDestination{ 3.4 }; // defines a variable of type double
    std::cout << typeid(milesToDestination).name() << '\n'; // prints a double value
    return 0;
}