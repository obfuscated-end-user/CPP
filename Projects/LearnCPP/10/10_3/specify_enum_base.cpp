// https://www.learncpp.com/cpp-tutorial/unscoped-enumeration-input-and-output/

#include <iostream>

enum Pet: int { // we've specified a base
    cat, // assigned 0
    dog, // assigned 1
    pig, // assigned 2
    whale, // assigned 3
};

int main() {
    Pet pet { 2 }; // ok: can initialize with integer
    pet = 3;       // compile error: can not assign with integer

    return 0;
}