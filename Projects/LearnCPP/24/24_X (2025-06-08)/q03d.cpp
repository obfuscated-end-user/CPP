// https://www.learncpp.com/cpp-tutorial/chapter-24-summary-and-quiz

/*
d) Each Monster type will have a different name, symbol, starting health, gold, and damage. Here is a table of stats for each monster Type:

Type	Name	Symbol	Health	Damage	Gold
dragon	dragon	D	    20	    4	    100
orc	    orc	    o	    4	    2	    25
slime	slime	s	    1	    1	    10

Next step is to write a Monster constructor, so we can create monsters. The Monster constructor should take a Type enum as a parameter, and then create a Monster with the appropriate stats for that kind of monster.

There are a number of different ways to implement this (some better, some worse). However in this case, because all of our monster attributes are predefined (not random or customized per creature), we can use a lookup table. Our lookup table will be a C-style array of Creature, where indexing the array with a Type will return the appropriate Creature for that Type.

Since this Creature table is specific to Monster, we can define it inside the Monster class as static inline Creature monsterData[] { }, initialized with our Creature elements.

Our Monster constructor is then easy: we can call the Creature copy constructor and pass it the appropriate Creature from our monsterData table.

The following program should compile:

```
#include <iostream>
#include <string>

int main()
{
	Monster m{ Monster::Type::orc };
	std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";

	return 0;
}
```

and print:

```
A orc (o) was created.
```
*/

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
};

int main() {
    Monster m { Monster::Type::orc };
	std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";

	return 0;
}