// https://www.learncpp.com/cpp-tutorial/chapter-24-summary-and-quiz

/*
f) We’re finally set to write our game logic!

Here are the rules for the game:

The player encounters one randomly generated monster at a time.
For each monster, the player has two choices: (R)un or (F)ight.
If the player decides to Run, they have a 50% chance of escaping.
If the player escapes, they move to the next encounter with no ill effects.
If the player does not escape, the monster gets a free attack, and the player chooses their next action.
If the player chooses to fight, the player attacks first. The monster’s health is reduced by the player’s damage.
If the monster dies, the player takes any gold the monster is carrying. The player also levels up, increasing their level and damage by 1.
If the monster does not die, the monster attacks the player back. The player’s health is reduced by the monster’s damage.
The game ends when the player has died (loss) or reached level 20 (win)
If the player dies, the game should tell the player what level they were and how much gold they had.
If the player wins, the game should tell the player they won, and how much gold they had

Here’s a sample game session:

Enter your name: Jesus
Welcome, Jesus
You have encountered a slime (s).
(R)un or (F)ight: f
You hit the slime for 1 damage.
You killed the slime.
You are now level 2.
You found 10 gold.
You have encountered a dragon (D).
(R)un or (F)ight: r
You failed to flee.
The dragon hit you for 4 damage.
(R)un or (F)ight: r
You successfully fled.
You have encountered a orc (o).
(R)un or (F)ight: f
You hit the orc for 2 damage.
The orc hit you for 2 damage.
(R)un or (F)ight: f
You hit the orc for 2 damage.
You killed the orc.
You are now level 3.
You found 25 gold.
You have encountered a dragon (D).
(R)un or (F)ight: r
You failed to flee.
The dragon hit you for 4 damage.
You died at level 3 and with 35 gold.
Too bad you can’t take it with you!

Hint: Create 4 functions:

	The main() function should handle game setup (creating the Player) and the main game loop.
	fightMonster() handles the fight between the Player and a single Monster, including asking the player what they want to do, handling the run or fight cases.
	attackMonster() handles the player attacking the monster, including leveling up.
	attackPlayer() handles the monster attacking the player.
*/

#include "Random.h" // https://www.learncpp.com/cpp-tutorial/global-random-numbers-random-h
#include <array>
#include <iostream>
#include <string>
#include <string_view>

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
		std::cout << "You killed the " << monster.getName() << ".\n";
		player.levelUp();
		std::cout << "You are now level " << player.getLevel() << ".\n";
		std::cout << "You found " << monster.getGold() << " gold.\n";
		player.addGold(monster.getGold());
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
	while (!monster.isDead() && !player.isDead()) {
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