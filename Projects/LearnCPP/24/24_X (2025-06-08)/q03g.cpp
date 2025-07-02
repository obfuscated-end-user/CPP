// https://www.learncpp.com/cpp-tutorial/chapter-24-summary-and-quiz

/*
g) Extra credit:
Reader Tom didn’t sharpen his sword enough to defeat the mighty dragon. Help him by implementing the following potions in different sizes:

Type		Effect(Small)   Effect (Medium) Effect (Large)
Health		+2 Health		+2 Health		+5 Health
Strength	+1 Damage		+1 Damage		+1 Damage
Poison		-1 Health		-1 Health		-1 Health

Feel free to get creative and add more potions or change their effects!

The player has a 30% chance of finding a potion after every won fight and has the choice between drinking or not drinking it. If the player doesn’t drink the potion, it disappears. The player doesn’t know what type of potion was found until the player drinks it, at which point the type and size of the potion is revealed and the effect is applied.

In the following example, the player found a poison potion and died from drinking it (Poison was much more damaging in this example)

```
You have encountered a slime (s).
(R)un or (F)ight: f
You hit the slime for 1 damage.
You killed the slime.
You are now level 2.
You found 10 gold.
You found a mythical potion! Do you want to drink it? [y/n]: y
You drank a Medium potion of Poison
You died at level 2 and with 10 gold.
Too bad you can't take it with you!
```

Hint: Add a Potion class that has a type and size member variable, along with a member function that returns its name and a static member function the creates a random Potion, similar to the getRandomMonster() function.
In the Player class, add a drinkPotion() member function the applies the potion’s effect.
*/

#include "Random.h" // https://www.learncpp.com/cpp-tutorial/global-random-numbers-random-h
#include <array>
#include <iostream>
#include <sstream>
#include <string>
#include <string_view>

class Potion {
public:
	// All possible types of potions
	enum Type {
		health,
		strength,
		poison,

		// For random potion generation
		max_type
	};

	enum Size {
		small,
		medium,
		large,

		max_size
	};

private:
	Type m_type {};
	Size m_size {};

public:
	Potion(Type type, Size size)
		: m_type { type }
		, m_size { size } {}

	Type getType() const {
		return m_type;
	}

	Size getSize() const {
		return m_size;
	}

	// The names of potions are compile-time literals, we can
	// return a std::string_view.
	static std::string_view getPotionTypeName(Type type) {
		static constexpr std::string_view names[] {
			"Health",
			"Strength",
			"Poison"
		};

		return names[type];
	}

	static std::string_view getPotionSizeName(Size size) {
		static constexpr std::string_view names[] {
			"Small",
			"Medium",
			"Large"
		};

		return names[size];
	}

	std::string getName() const {
		// We use a std::stringstream, but this could also be solved using
		// std::string.
		// We first use std::stringstream in lesson 7.13
		std::stringstream result {};

		result << getPotionSizeName(getSize()) << " potion of " << getPotionTypeName(getType());

		// We can extract the string from an std::stringstream by using the str()
		// member function.
		return result.str();
	}

	static Potion getRandomPotion() {
		return Potion {
			static_cast<Type>(Random::get(0, max_type - 1)),
			static_cast<Size>(Random::get(0, max_size - 1))
		};
	}
};

class Creature {
protected:
	std::string m_name {};
	char m_symbol {};
	int m_health {};
	int m_damage {};
	int m_gold {};

public:
	Creature(std::string_view name, char symbol, int health, int damage, int gold)
		: m_name { name }
		, m_symbol { symbol }
		, m_health { health }
		, m_damage { damage }
		, m_gold { gold } {}

	const std::string& getName() const {
		return m_name;
	}

	char getSymbol() const {
		return m_symbol;
	}

	int getHealth() const {
		return m_health;
	}

	int getDamage() const {
		return m_damage;
	}

	int getGold() const {
		return m_gold;
	}

	void reduceHealth(int health) {
		m_health -= health;
	}

	bool isDead() const {
		return m_health <= 0;
	}

	void addGold(int gold) {
		m_gold += gold;
	}
};

class Player : public Creature {
	int m_level { 1 };

public:
	Player(std::string_view name) : Creature { name, '@', 10, 1, 0 } {}

	void levelUp() {
		++m_level;
		++m_damage;
	}

	// Applies a potion's effect to the player
	void drinkPotion(const Potion& potion) {
		switch (potion.getType()) {
			case Potion::health:
				// Only a health potion's size affects its power. All other
				// potions are independent of size.
				m_health += ((potion.getSize() == potion.large) ? 5 : 2);
				break;
			case Potion::strength:
				++m_damage;
				break;
			case Potion::poison:
				reduceHealth(1);
				break;
				// Handle max_type to silence the compiler warning. Don't use default:
				// because we want the compiler to warn us if we add a new potion but
				// forget to implement its effect.
			case Potion::max_type:
				break;
		}
	}

	int getLevel() const {
		return m_level;
	}

	bool hasWon() const {
		return m_level >= 20;
	}
};

class Monster : public Creature {
public:
	enum Type {
		dragon,
		orc,
		slime,
		max_types
	};

private:
	inline static Creature monsterData[] {
		Creature { "dragon", 'D', 20, 4, 100 },
		Creature { "orc", 'o', 4, 2, 25 },
		Creature { "slime", 's', 1, 1, 10 }
	};

	static_assert(std::size(monsterData) == max_types);

public:
	Monster(Type type) : Creature { monsterData[type] } {}

	static Monster getRandomMonster() {
		int num { Random::get(0, max_types - 1) };
		return Monster { static_cast<Type>(num) };
	}
};

// We moved this out of attackMOnster() to keep the function shorter.
void onMonsterKilled(Player& player, const Monster& monster) {
	std::cout << "You killed the " << monster.getName() << ".\n";
	player.levelUp();
	std::cout << "You are now level " << player.getLevel() << ".\n";
	std::cout << "You found  " << player.getGold() << " gold.\n";
	player.addGold(monster.getGold());

	// 30% chance of finding a potion
	constexpr int potionChance { 30 };
	if (Random::get(1, 100) <= potionChance) {
		// Generate a random potion
		auto potion { Potion::getRandomPotion() };

		std::cout << "You found a mythical potion! Do you want to drink it? [y/n]: ";
		char choice {};
		std::cin >> choice;

		if (choice == 'Y' || choice == 'y') {
			// Apply the effect
			player.drinkPotion(potion);
			// Reveal the potion type and size
			std::cout << "You drank a " << potion.getName() << ".\n";
		}
	}
}

// This function handles the player attacking the monster
void attackMonster(Player& player, Monster& monster) {
	// If the player is dead, we can't attack the monster
	if (player.isDead())
		return;
	
	std::cout << "You hit the " << monster.getName() << " for " << player.getDamage() << " damage.\n";

	// Reduce the monster's health by the player's damage
	monster.reduceHealth(player.getDamage());

	// If the monster is now dead, level the player up
	if (monster.isDead()) {
		// Reward the player
		onMonsterKilled(player, monster);
	}
}

// This function handles the monster attacking the player
void attackPlayer(const Monster& monster, Player& player) {
	// If monster is dead, it can't attack the player
	if (monster.isDead())
		return;

	// Reduce the player's health by the monster's damage
	player.reduceHealth(monster.getDamage());
	std::cout << "The " << monster.getName() << " hit you for " << monster.getDamage() << " damage.\n";
}

// This function handles the entire fight between a player and a randomly generated monster
void fightMonster(Player& player) {
	// First randomly generate monster
	Monster monster { Monster::getRandomMonster() };
	std::cout << "You have encountered a " << monster.getName() << " (" << monster.getSymbol() << ").\n";

	// While the monster isn't dead and the player isn't dead, the fight continues
	while (!monster.isDead() &&  !player.isDead()) {
		std::cout << "(R)un or (F)ight: ";
		char input {};
		std::cin >> input;
		if (input == 'R' || input == 'r') {
			// 50% chance of fleeing successully
			if (Random::get(1, 2) == 1) {
				std::cout << "You successfully fled.\n";
				return; // success ends the encounter
			} else {
				// Failure to flee gives the monster a free attack on the player
				std::cout << "You failed to flee.\n";
				attackPlayer(monster, player);
				continue;
			}
		}

		if (input == 'F' || input == 'f') {
			// Player attacks first, monster attacks second
			attackMonster(player, monster);
			attackPlayer(monster, player);
		}
	}
}

int main() {
	std::cout << "Enter your name: ";
	std::string playerName;
	std::cin >> playerName;

	Player player { playerName };
	std::cout << "Welcome, " << player.getName() << '\n';

	// If the player isn't dead and hasn't won yet, the game continues
	while (!player.isDead() && !player.hasWon())
		fightMonster(player);

	// At this point, the player is either dead or has won
	if (player.isDead()) {
		std::cout << "You died at level " << player.getLevel() << " and with " << player.getGold() << " gold.\n";
		std::cout << "Too bad you can't take it with you!\n";
	} else {
		std::cout << "You won the game with " << player.getGold() << " gold!\n";
	}

	return 0;
}