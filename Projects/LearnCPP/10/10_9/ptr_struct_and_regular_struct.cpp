// https://www.learncpp.com/cpp-tutorial/member-selection-with-pointers-and-references/

#include <iostream>
#include <string>

struct Paw {
    int claws{};
};

struct Animal {
    std::string name{};
    Paw paw{};
};

int main() {
    Animal puma{ "Puma", { 5 } };

    Animal* ptr{ &puma };

    // ptr is a pointer, use ->
    // paw is not a pointer, use .

    std::cout << (ptr->paw).claws << '\n';

    return 0;
}

// Note that in the case of (ptr->paw).claws, parentheses aren’t necessary since both operator-> and operator. evaluate in left to right order, but it does help readability slightly.