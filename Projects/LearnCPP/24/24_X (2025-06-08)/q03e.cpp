// https://www.learncpp.com/cpp-tutorial/chapter-24-summary-and-quiz

/*
e) Finally, add a static function to Monster named getRandomMonster(). This function should pick a random number from 0 to max_types-1 and return a monster (by value) with that Type (you’ll need to static_cast the int to a Type to pass it to the Monster constructor).

Lesson 8.15 -- Global random numbers (Random.h) contains code you can use to pick a random number.

The following main function should run:

```
#include <iostream>
#include <string>

int main()
{
	for (int i{ 0 }; i < 10; ++i)
	{
		Monster m{ Monster::getRandomMonster() };
		std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";
	}

	return 0;
}
```

The results of this program should be randomized.
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

int main() {
	for (int i { 0 }; i < 10; ++i) {
		Monster m { Monster::getRandomMonster() };
		std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";
	}

	return 0;
}