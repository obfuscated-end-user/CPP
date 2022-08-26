// https://www.learncpp.com/cpp-tutorial/chapter-10-summary-and-quiz/

/*
Question #1

In designing a game, we decide we want to have monsters, because everyone likes fighting monsters. Declare a struct that represents your monster. The monster should have a type that can be one of the following: an ogre, a dragon, an orc, a giant spider, or a slime. Use an enum class for this.

Each individual monster should also have a name (use a std::string or std::string_view), as well as an amount of health that represents how much damage they can take before they die. Write a function named printMonster() that prints out all of the struct’s members. Instantiate an ogre and a slime, initialize them using an initializer list, and pass them to printMonster().

Your program should produce the following output:

This Ogre is named Torg and has 145 health.
This Slime is named Blurp and has 23 health.
*/

#include <iostream>
#include <string>

enum monsterType {
    ogre,
    dragon,
    orc,
    giantSpider,
    slime,
};

struct Monster {
    monsterType type {};
    std::string name {};
    double health {1};
};

void printMonster(const Monster& monster) {
    std::string type {};
    switch(monster.type) {
        case ogre: type = "Ogre"; break;
        case dragon: type = "Dragon"; break;
        case orc: type = "Orc"; break;
        case giantSpider: type = "Giant Spider"; break;
        case slime: type = "Slime"; break;
        default: type = "???"; break;
    }
    std::cout << "This " << type << " is named " << monster.name << " and has " << monster.health << " health.\n";
}

int main() {
    Monster Ogre { ogre, "Torg", 145};
    Monster Slime { slime, "Blurp", 23};

    printMonster(Ogre);
    printMonster(Slime);

    return 0;
}

/*
#include <iostream>
#include <string>
#include <string_view> // C++17

// Define our different monster types as an enum
enum class MonsterType
{
	ogre,
	dragon,
	orc,
	giant_spider,
	slime
};

// Our monster struct represents a single monster
struct Monster
{
	MonsterType type{};
	std::string name{};
	int health{};
};

// Return the name of the monster's type as a string
// Since this could be used elsewhere, it's better to make this its own function
constexpr std::string_view getMonsterTypeString(MonsterType type)
{
	switch (type)
	{
	case MonsterType::ogre:          return "Ogre";
	case MonsterType::dragon:        return "Dragon";
	case MonsterType::orc:           return "Orc";
	case MonsterType::giant_spider:  return "Giant Spider";
	case MonsterType::slime:         return "Slime";
	}

	return "Unknown";
}

// Print our monster's stats
void printMonster(const Monster& monster)
{
	std::cout << "This " << getMonsterTypeString(monster.type) <<
		" is named " << monster.name <<
		" and has " << monster.health << " health.\n";
}

int main()
{
	Monster ogre{ MonsterType::ogre, "Torg", 145 };
	Monster slime{ MonsterType::slime, "Blurp", 23 };

	printMonster(ogre);
	printMonster(slime);

	return 0;
}
*/