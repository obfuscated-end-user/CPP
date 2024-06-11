// https://www.learncpp.com/cpp-tutorial/arrays-part-ii

/*
Set up an enum with the names of the following animals: chicken, dog, cat, elephant, duck, and snake. Put the enum in a namespace. Define an array with an element for each of these animals, and use an initializer list to initialize each element to hold the number of legs that animal has.
*/

namespace Animals {
    enum Animals {
        chicken,
        dog,
        cat,
        elephant,
        duck,
        snake,
    };
}

Animals::Animals animalList[] {Animals::chicken, Animals::dog, Animals::cat, Animals::elephant, Animals::duck, Animals::snake};

/*
// answer:
#include <iostream>

namespace animals
{
    enum Animals // The name of this enum could be omitted since it isn't used anywhere
    {
        chicken,
        dog,
        cat,
        elephant,
        duck,
        snake,
        max_animals
    };
}

int main()
{
    int legs[animals::max_animals]{ 2, 4, 4, 4, 2, 0 };

    std::cout << "An elephant has " << legs[animals::elephant] << " legs.\n";

    return 0;
}*/