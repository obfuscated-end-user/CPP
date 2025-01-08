// https://www.learncpp.com/cpp-tutorial/chapter-16-summary-and-quiz

/*
Let’s say you’re writing a game where the player can hold 3 types of items: health potions, torches, and arrows.
> Step #1
Define an unscoped enum in a namespace to identify the different types of items. Define an std::vector to store the number of each item type the player is carrying. The player should start with 1 health potion, 5 torches, and 10 arrows. Assert to make sure the array has the correct number of initializers.
Hint: Define a count enumerator and use it inside the assert.
The program should output the following:
You have 16 total items
*/

#include <cassert>
#include <iostream>
#include <vector>

namespace Items {
    enum Type {
        health_potion,
        torch,
        arrow,
        max_items
    };
}

// Inventory items should have integral quantities so we don't need a function template here
int countTotalItems(const std::vector<int>& inventory) {
    int sum { 0 };
    for (auto e : inventory)
        sum += e;
    return sum;
}

int main() {
    std::vector inventory { 1, 5, 10 };
    assert(std::size(inventory) == Items::max_items);   // make sure our inventory has the correct number of initializers

    std::cout << "You have " << countTotalItems(inventory) << " total items\n";

    return 0;
}