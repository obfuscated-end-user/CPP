// https://www.learncpp.com/cpp-tutorial/unscoped-enumeration-input-and-output/

#include <iostream>

enum Pet {
    cat, // assigned 0
    dog, // assigned 1
    pig, // assigned 2
    whale, // assigned 3
};

int main() {
    Pet pet { static_cast<Pet>(2) }; // convert integer 2 to a Pet
    pet = static_cast<Pet>(3);       // our pig evolved into a whale!

    return 0;
}