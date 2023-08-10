// https://www.learncpp.com/cpp-tutorial/chapter-13-comprehensive-quiz

#include <array>
#include <chrono>
#include <iostream>
#include <random>
#include <string>
#include <string_view>

namespace Random {
	inline std::mt19937 generate() {
		std::random_device rd;

		// Create seed_seq with high-res clock and 7 random numbers from std::random_device
		std::seed_seq ss{
			static_cast<std::seed_seq::result_type>(std::chrono::steady_clock::now().time_since_epoch().count()),
				rd(), rd(), rd(), rd(), rd(), rd(), rd() };

		return std::mt19937{ ss };
	}

	// Here's our global std::mt19937 object.
	// The inline keyword means we only have one global instance for our whole program.
	inline std::mt19937 mt{ generate() }; // generates a seeded std::mt19937 and copies it into our global object

	// Generate a random int between [min, max] (inclusive)
	inline int get(int min, int max) {
		return std::uniform_int_distribution{min, max}(mt);
	}

	template <typename T>
	inline T get(T min, T max) {
		return std::uniform_int_distribution<T>{min, max}(mt);
	}

	template <typename R, typename S, typename T>
	inline R get(S min, T max) {
		return get<R>(static_cast<R>(min), static_cast<R>(max));
	}
}

class Monster {
public:
    enum Type {
        dragon,
        goblin, 
        ogre,
        orc,
        skeleton,
        troll,
        vampire,
        zombie,
        max_monster_types
    };
private:
    Type m_type;
    std::string m_name;
    std::string m_roar;
    int m_hitPoints;

public:
    Monster(Type type, std::string_view name, std::string_view roar, int hitPoints)
        : m_type {type}, m_name {name}, m_roar {roar}, m_hitPoints {m_hitPoints} {}

    std::string_view getTypeString() const {
        switch (m_type) {
            case Type::dragon: return "dragon";
            case Type::goblin: return "goblin";
            case Type::ogre: return "ogre";
            case Type::orc: return "orc";
            case Type::skeleton: return "skeleton";
            case Type::troll: return "troll";
            case Type::zombie: return "zombie";
            default: return "???";
        }
    }

    void print() const {
        std::cout << m_name << " the " << getTypeString() << " has " << m_hitPoints << " hit points and says " << m_roar << '\n';
    }
};

namespace MonsterGenerator {
    Monster generate() {
        int maxIndex = Monster::Type::max_monster_types - 1;
        auto type = static_cast<Monster::Type>(Random::get(0, maxIndex));
        int hitPoints = Random::get(1, 100);

        static constexpr std::array s_names = {"Blarg", "Moog", "Pksh", "Tyrn", "Mort", "Hans"};
        constexpr std::array s_roars = {"*ROAR*", "*peep*", "*squeal*", "*whine*", "*hum*", "*burp*"};

        static auto name = s_names[Random::get<std::size_t>(0, s_names.size() - 1)];
        auto roar = s_roars[Random::get<std::size_t>(0, s_roars.size() - 1)];

        return Monster {type, name, roar, hitPoints};
        // return Monster { Monster::skeleton, "Bones", "*rattle*", 4};
    }
}

int main() {
	Monster skeleton{ Monster::skeleton, "Bones", "*rattle*", 4 };
    skeleton.print();

    // random monster
    Monster m1{ MonsterGenerator::generate() };
	m1.print();
    Monster m2{ MonsterGenerator::generate() };
	m2.print();
    Monster m3{ MonsterGenerator::generate() };
	m3.print();

	return 0;
}