// https://www.learncpp.com/cpp-tutorial/member-selection-with-pointers-and-references
// don't refer to operator. as "periods"

#include <iostream>
#include <string>

struct Paw {
    int claws {};
};

struct Animal {
    std::string name {};
    Paw paw {};
};

int main() {
    Animal puma { "Puma", { 5 } };

    Animal* ptr { &puma };

    // ptr is a pointer, use ->
    // paw is not a poiter, use .

    std::cout << (ptr->paw).claws << '\n';

    return 0;
}