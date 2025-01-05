// https://www.learncpp.com/cpp-tutorial/array-indexing-and-length-using-enumerators

/*
Create a program-defined enum (inside a namespace) containing the names of the following animals: chicken, dog, cat, elephant, duck, and snake. Define an array with an element for each of these animals, and use an initializer list to initialize each element to hold the number of legs that animal has. Assert that the array has the correct number of initializers.
Write a main() function that prints the number of legs an elephant has, using the enumerator.
*/

#include <cassert>
#include <iostream>
#include <vector>

namespace Animals {
    enum Animals {
        chicken,
        dog,
        cat,
        elephant,
        duck,
        snake,
        max_animals
    };

    const std::vector legs { 2, 4, 4, 4, 2, 0 };
}

int main() {
    // Ensure the number of legs is the same as the number of animals
    assert(std::size(Animals::legs) == Animals::max_animals);

    std::cout << "An elephant has " << Animals::legs[Animals::elephant] << " legs.\n";

    return 0;
}