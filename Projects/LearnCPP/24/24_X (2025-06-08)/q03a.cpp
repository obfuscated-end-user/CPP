// https://www.learncpp.com/cpp-tutorial/chapter-24-summary-and-quiz

/*
Challenge time! The following quiz question is more difficult and lengthy. We’re going to write a simple game where you fight monsters. The goal of the game is to collect as much gold as you can before you die or get to level 20.

Our program is going to consist of 3 classes: a Creature class, a Player class, and a Monster class. Player and Monster both inherit from Creature.

a) First create the Creature class. Creatures have 5 attributes: A name (std::string), a symbol (a char), an amount of health (int), the amount of damage they do per attack (int), and the amount of gold they are carrying (int). Implement these as class members. Write a full set of getters (a get function for each member). Add three other functions: void reduceHealth(int) reduces the Creature’s health by an integer amount. bool isDead() returns true when the Creature’s health is 0 or less. void addGold(int) adds gold to the Creature.

The following program should run:

```
#include <iostream>
#include <string>

int main()
{
	Creature o{ "orc", 'o', 4, 2, 10 };
	o.addGold(5);
	o.reduceHealth(1);
	std::cout << "The " << o.getName() << " has " << o.getHealth() << " health and is carrying " << o.getGold() << " gold.\n";

	return 0;
}
```

And produce the result:

```
The orc has 3 health and is carrying 15 gold.
```
*/

#include <iostream>
#include <string>
#include <string_view>  // Requires C++17

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

int main() {
	Creature o { "orc", 'o', 4, 2, 10 };
	o.addGold(5);
	o.reduceHealth(1);
	std::cout << "The " << o.getName() << " has " << o.getHealth() << " health and is carrying " << o.getGold() << " gold.\n";

	return 0;
}