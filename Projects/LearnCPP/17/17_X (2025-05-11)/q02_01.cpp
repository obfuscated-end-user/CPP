// https://www.learncpp.com/cpp-tutorial/chapter-17-summary-and-quiz

/*
In this quiz, we’re going to implement Roscoe’s potion emporium, the finest potion shop in the land! This is going to be a bigger challenge.
Implement a program that outputs the following:

```
Welcome to Roscoe's potion emporium!
Enter your name: Bob
Hello, Bob, you have 85 gold.
Here is our selection for today:
0) healing costs 20
1) mana costs 30
2) speed costs 12
3) invisibility costs 50
Enter the number of the potion you'd like to buy, or 'q' to quit: a
That is an invalid input. Try again: 3
You purchased a potion of invisibility. You have 35 gold left.
Here is our selection for today:
0) healing costs 20
1) mana costs 30
2) speed costs 12
3) invisibility costs 50
Enter the number of the potion you'd like to buy, or 'q' to quit: 4
That is an invalid input. Try again: 2
You purchased a potion of speed. You have 23 gold left.
Here is our selection for today:
0) healing costs 20
1) mana costs 30
2) speed costs 12
3) invisibility costs 50
Enter the number of the potion you'd like to buy, or 'q' to quit: 2
You purchased a potion of speed. You have 11 gold left.
Here is our selection for today:
0) healing costs 20
1) mana costs 30
2) speed costs 12
3) invisibility costs 50
Enter the number of the potion you'd like to buy, or 'q' to quit: 4
You can not afford that.
Here is our selection for today:
0) healing costs 20
1) mana costs 30
2) speed costs 12
3) invisibility costs 50
Enter the number of the potion you'd like to buy, or 'q' to quit: q
Your inventory contains: 
2x potion of speed
1x potion of invisibility
You escaped with 11 gold remaining.
Thanks for shopping at Roscoe's potion emporium!
```

The player starts with a randomized amount of gold, between 80 and 120.
Sound fun? Let’s do it! Because this will be hard to implement all at once, we’ll develop this in steps.
> Step #1
Create a Potion namespace containing an enum named Type containing the potion types. Create two std::array: an int array to hold the potion costs, and a std::string_view array to hold the potion names.
Also write a function named shop() that enumerates through the list of Potions and prints their numbers, names, and cost.
The program should output the following:

```
Here is our selection for today:
0) healing costs 20
1) mana costs 30
2) speed costs 12
3) invisibility costs 50
```
Hint: We show a method for iterating through an enumeration using a range-based for-loop in lesson 17.6 -- std::array and enumerations.
*/

#include <array>
#include <iostream>
#include <string_view>

namespace Potion {
    enum Type {
        healing,
        mana,
        speed,
        invisibility,
        max_potions
    };

    constexpr std::array types { healing, mana, speed, invisibility };  // An array of our enumerators

    // We could put these in a struct, but since we only have two attributes we'll keep them separate for now
    // We will explicitly define the element type so we don't have to use the sv suffix
    constexpr std::array<std::string_view, max_potions> name { "healing", "mana", "speed", "invisibility" };
    constexpr std::array cost { 20, 30, 12, 50 };

    static_assert(std::size(types) == max_potions); // ensure 'all' ccontains the correct number of enumerators
    static_assert(std::size(cost) == max_potions);
    static_assert(std::size(name) == max_potions);
};

void shop() {
    std::cout << "Here is our selection for today:\n";

    for (auto p: Potion::types)
        std::cout << p << ") " << Potion::name[p] << " costs " << Potion::cost[p] << '\n';
}

int main() {
    shop();

    return 0;
}