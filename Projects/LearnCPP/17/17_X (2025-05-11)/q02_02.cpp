// https://www.learncpp.com/cpp-tutorial/chapter-17-summary-and-quiz

/*
Create a Player class to store the player’s name, potion inventory, and gold. Add the introductory and goodbye text for Roscoe’s emporium. Get the player’s name and randomize their gold.
Use the “Random.h” file in lesson 8.15 -- Global random numbers (Random.h) to make randomization easy.
The program should output the following:

```
Welcome to Roscoe's potion emporium!
Enter your name: Bob
Hello, Bob, you have 84 gold.
Here is our selection for today:
0) healing costs 20
1) mana costs 30
2) speed costs 12
3) invisibility costs 50
Thanks for shopping at Roscoe's potion emporium!
```
Hint: We show a method for iterating through an enumeration using a range-based for-loop in lesson 17.6 -- std::array and enumerations.
*/

#include <array>
#include <iostream>
#include <string_view>
#include "Random.h"

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

class Player {
private:
    static constexpr int s_minStartingGold { 80 };
    static constexpr int s_maxStartingGold { 120 };

    std::string m_name {};
    int m_gold {};
    std::array<int, Potion::max_potions> m_inventory {};

public:
    explicit Player(std::string_view name) :
        m_name { name },
        m_gold { Random::get(s_minStartingGold, s_maxStartingGold) }
    {}

    int gold() const {
        return m_gold;
    }

    int inventory(Potion::Type p) const {
        return m_inventory[p];
    }
};

void shop() {
    std::cout << "Here is our selection for today:\n";

    for (auto p: Potion::types)
        std::cout << p << ") " << Potion::name[p] << " costs " << Potion::cost[p] << '\n';
}

int main() {
    std::cout << "Welcome to Roscoe's potion emporium!\n";
    std::cout << "Enter your name: ";

    std::string name {};
    std::getline(std::cin >> std::ws, name);    // read a full line of text into name

    Player player { name };

    std::cout << "Hello, " << name << ", you have " << player.gold() << " gold.\n\n";

    shop();

    std::cout << "\nThanks for shopping at Roscoe's potion emporium!\n";

    return 0;
}