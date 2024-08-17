// https://www.learncpp.com/cpp-tutorial/global-random-numbers-random-h

#include "Random.h" // defines Random::mt, Random::get(), and Random::generate()
#include <cstddef>
#include <iostream>

int main() {
    // We can use Random::get() to generate random numbers
    std::cout << Random::get(1, 6) << '\n';     // returns int between 1 and 6
    std::cout << Random::get(1u, 6u) << '\n';   // returns unsigned int between 1 and 6

    // The following uses a template type argument
    std::cout << Random::get<std::size_t>(1, 6u) << '\n';   // returns std::size_t between 1 and 6

    // We can access Random::mt directly if we have our own distribution

    // Let's create a reusable random number generator that generates uniform numbers between 1 and 6
    std::uniform_int_distribution die6 { 1, 6 };    // for C++14, use sstd::uniform_int_distribution<> die6 { 1, 6 };

    for (int count { 1 }; count <= 10; ++count) {
        std::cout << die6(Random::mt) << '\t';  // generate a roll of die here
    }

    std::cout << '\n';

    return 0;
}