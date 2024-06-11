/*
    RELEARN ALL OF THESE:
    - syntax
    - basic stuff:
        - variables
            - types
            - data structures
        - operators
        - errors (whatever you call them)
        - exception handling
        - conditionals
        - loops
        - functions
        - classes
            - structs
            - something like inheritance in python
    - vague stuff
        - #include
        - compiling
        - linking
        - folder structure
        - scope
        - static and other keywords
    - gui
    
    also, force yourself to make random projects in order to make yourself type code more.
    EXAMPLES:
        - games
            - snake
            - tetris
            - a platformer
            - stg
        - calculator
        - something that randomizes
        - soemthing involving language learning
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
// fuck using namespace std;

int main() {
    int variable1;
    std::cout << "\a";
    std::cout << "enter something" << std::endl;
    std::cin >> variable1;
    std::cout << "You entered: " << variable1 << std::endl;

    for (int i = 1; i < 10; i++) {
        std::cout << "count: " << i << std::endl;
    }
}