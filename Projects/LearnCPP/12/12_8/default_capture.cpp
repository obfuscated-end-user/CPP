// https://www.learncpp.com/cpp-tutorial/lambda-captures/

#include <algorithm>
#include <array>
#include <iostream>

int main() {
    std::array areas { 100, 25, 121, 40, 56 };

    int width;
    int height;

    std::cout << "Enter width and height: ";
    std::cin >> width >> height;

    auto found = std::find_if(areas.begin(), areas.end(),
                            [=](int knownArea) { // will default capture width and height by value
                                return (width * height == knownArea); // because they're mentioned here
                            });

    if (found == areas.end())
        std::cout << "I don't know this area :(\n";
    else
        std::cout << "Area found :)\n";

    return 0;
}

/*
To capture all used variables by value, use a capture value of =.
To capture all used variables by reference, use a capture value of &.

Default captures can be mixed with normal captures. We can capture some variables by value and others by reference, but each variable can only be captured once.

int health{ 33 };
int armor{ 100 };
std::vector<CEnemy> enemies{};

// Capture health and armor by value, and enemies by reference.
[health, armor, &enemies](){};

// Capture enemies by reference and everything else by value.
[=, &enemies](){};

// Capture armor by value and everything else by reference.
[&, armor](){};

// Illegal, we already said we want to capture everything by reference.
[&, &armor](){};

// Illegal, we already said we want to capture everything by value.
[=, armor](){};

// Illegal, armor appears twice.
[armor, &health, &armor](){};

// Illegal, the default capture has to be the first element in the capture group.
[armor, &](){};
*/