// https://www.learncpp.com/cpp-tutorial/chapter-24-summary-and-quiz

/*
b) Now we’re going to create the Player class. The Player class inherits from Creature. Player has one additional member, the player’s level, which starts at 1. The player has a custom name (entered by the user), uses symbol ‘@’, has 10 health, does 1 damage to start, and has no gold. Write a function called levelUp() that increases the player’s level and damage by 1. Also write a getter for the level member. Finally, write a function called hasWon() that returns true if the player has reached level 20.

Write a new main() function that asks the user for their name and produces the output as follows:

```
Enter your name: Alex
Welcome, Alex.
You have 10 health and are carrying 0 gold.
```
*/

#include <iostream>
#include <string>
#include <string_view>  // std::string_view requires C++17

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

	int getLevel() const {
		return m_level;
	}

	bool hasWon() const {
		return m_level >= 20;
	}
};

int main() {
	std::cout << "Enter your name: ";
	std::string playerName;
	std::cin >> playerName;

	Player p { playerName };
	std::cout << "Welcome, " << p.getName() << ".\n";

	std::cout << "You have " << p.getHealth() << " health and are carrying " << p.getGold() << " gold.\n";

	return 0;
}