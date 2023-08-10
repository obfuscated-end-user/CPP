// https://stackoverflow.com/questions/29549873/stdmt19937-doesnt-return-random-number

#include <random>
#include <iostream>

static std::random_device rd;
static std::mt19937 rng {rd()};

int dice() {
    static std::uniform_int_distribution<int> uid (1,6);
    return uid(rng); // use rng as a generator
}

int main() {
    for (int i = 0; i < 10; ++i)
        std::cout << dice() << ' ';   
}