// https://www.learncpp.com/cpp-tutorial/chapter-11-comprehensive-quiz

/*
Question #1

Pretend you’re writing a game where the player can hold 3 types of items: health potions, torches, and arrows. Create an enum to identify the different types of items, and an std::array to store the number of each item the player is carrying (the enumerators are used as indexes of the array). The player should start with 2 health potions, 5 torches, and 10 arrows. Write a function called countTotalItems() that returns how many items the player has in total. Have your main() function print the output of countTotalItems() as well as the number of torches.
*/

#include <iostream>
#include <array>
#include <numeric>

// Create an enum to identify the different types of items
enum Items {
    healthPotions,
    torches,
    arrows,
};

// Write a function called countTotalItems() that returns how many items the player has in total.
int countTotalItems(const std::array<int, 3>& player) {
    return std::reduce(player.begin(), player.end());
}


int main() {
    // an std::array to store the number of each item the player is carrying (the enumerators are used as indexes of the array)
    // The player should start with 2 health potions, 5 torches, and 10 arrows.
    std::array playerItems {2, 5, 10};

    // Have your main() function print the output of countTotalItems()
    std::cout << "Total number of items: " << countTotalItems(playerItems) << '\n';
    
    // as well as the number of torches.
    std::cout << "Total number of torches: " << playerItems[Items::torches];
    return 0;
}

/*
#include <array>
#include <numeric> // std::reduce
#include <iostream>

// We want to use ItemTypes to index an array. Use enum rather than enum class.
enum ItemTypes
{
  item_health_potion,
  item_torch,
  item_arrow,
  max_items
};

using inventory_t = std::array<int, ItemTypes::max_items>;

int countTotalItems(const inventory_t& items)
{
  return std::reduce(items.begin(), items.end());
}

int main()
{
  inventory_t items{ 2, 5, 10 };

  std::cout << "The player has " << countTotalItems(items) << " item(s) in total.\n";

  // We can access individual items using the enumerators:
  std::cout << "The player has " << items[ItemTypes::item_torch] << " torch(es)\n";

  return 0;
}
*/