// https://www.learncpp.com/cpp-tutorial/lambda-captures

#include <algorithm>
#include <array>
#include <iostream>
#include <string>

struct Car {
    std::string make;
    std::string model;
};

int main() {
    std::array<Car, 3> cars { {
        { "Volkswagen", "Golf" },
        { "Toyota", "Corolla" },
        { "Honda", "Civic" }
    } };    // 3 curly braces

    int comparisons = 0;

    std::sort(cars.begin(), cars.end(), 
        // Capture @comparisons by reference.
        [&comparisons](const auto& a, const auto& b) {
            // We captured comparisons by reference. We can modify it without "mutable".
            ++comparisons;

            // Sort the cars by their make.
            return (a.make < b.make);
        }
    );

    std::cout << "Comparisons: " << comparisons << '\n';

    for (const auto& car : cars)
        std::cout << car.make << ' ' << car.model << '\n';

    return 0;
}

/*
Multiple variables can be captured by separating them with a comma. This can include a mix of variables captured by value or by reference:

int health{ 33 };
int armor{ 100 };
std::vector<CEnemy> enemies{};

// Capture health and armor by value, and enemies by reference.
[health, armor, &enemies](){};
*/