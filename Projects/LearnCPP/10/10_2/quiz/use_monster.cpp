// https://www.learncpp.com/cpp-tutorial/unscoped-enumerations/

// Put the MonsterType enumeration inside a namespace. Then, create a main() function and instantiate a troll. The program should compile.

namespace monstertype {
    enum MonsterType {
        orcs,
        goblins,
        trolls,
        ogres,
        skeletons,
    };
}

int main() {
    monstertype::MonsterType troll = troll;

    return 0;
}