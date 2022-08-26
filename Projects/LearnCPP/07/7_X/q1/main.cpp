// https://www.learncpp.com/cpp-tutorial/chapter-7-comprehensive-quiz/

/*
In the chapter 4 comprehensive quiz, we wrote a program to simulate a ball falling off of a tower. Because we didn’t have loops yet, the ball could only fall for 5 seconds.

Take the program below and modify it so that the ball falls for as many seconds as needed until it reaches the ground.

In constants.h:

#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace myConstants
{
    inline constexpr double gravity { 9.8 }; // in meters/second squared
}
#endif

In your main code file:

#include <iostream>
#include "constants.h"

double calculateHeight(double initialHeight, int seconds)
{
    double distanceFallen { myConstants::gravity * seconds * seconds / 2 };
    double heightNow { initialHeight - distanceFallen };

    // Check whether we've gone under the ground
    // If so, set the height to ground-level
    if (heightNow < 0.0)
        return 0.0;
    else
        return heightNow;
}

void calculateAndPrintHeight(double initialHeight, int time)
{
    std::cout << "At " << time << " seconds, the ball is at height: " << calculateHeight(initialHeight, time) << "\n";
}

int main()
{
    std::cout << "Enter the initial height of the tower in meters: ";
    double initialHeight {};
    std::cin >> initialHeight;

    calculateAndPrintHeight(initialHeight, 0);
    calculateAndPrintHeight(initialHeight, 1);
    calculateAndPrintHeight(initialHeight, 2);
    calculateAndPrintHeight(initialHeight, 3);
    calculateAndPrintHeight(initialHeight, 4);
    calculateAndPrintHeight(initialHeight, 5);

    return 0;
}
*/

#include <iostream>
#include "constants.h"

double calculateHeight(double initialHeight, int seconds) {
    double distanceFallen { myConstants::gravity * seconds * seconds / 2 };
    double heightNow { initialHeight - distanceFallen };

    // Check whether we've gone under the ground
    // If so, set the height to ground-level
    if (heightNow < 0.0)
        return 0.0;
    else
        return heightNow;
}

void calculateAndPrintHeight(double initialHeight, int time) {
    if (initialHeight <= 0);
    else
        std::cout << "At " << time << " seconds, the ball is at height: " << calculateHeight(initialHeight, time) << "\n";
}

int main() {
    std::cout << "Enter the initial height of the tower in meters: ";
    double initialHeight {};
    std::cin >> initialHeight;
    /* calculateAndPrintHeight(initialHeight, 0);
    calculateAndPrintHeight(initialHeight, 1);
    calculateAndPrintHeight(initialHeight, 2);
    calculateAndPrintHeight(initialHeight, 3);
    calculateAndPrintHeight(initialHeight, 4);
    calculateAndPrintHeight(initialHeight, 5); */

    for (int i = 0; i < 5; ++i) {
        calculateAndPrintHeight(initialHeight, i);
        
    }
    return 0;
}

/*
// correct answer:

// same first function, don't need to rewrite it here

// Returns true if the ball hit the ground, false if the ball is still falling
bool calculateAndPrintHeight(double initialHeight, int time)
{
    double currentHeight { calculateHeight(initialHeight, time) };
    std::cout << "At " << time << " seconds, the ball is at height: " << currentHeight << "\n";

    return (currentHeight == 0.0);
}

int main()
{
    std::cout << "Enter the initial height of the tower in meters: ";
    double initialHeight;
    std::cin >> initialHeight;

    int seconds = 0;

    // returns true if the ground was hit
    while (!calculateAndPrintHeight(initialHeight, seconds))
        ++seconds;

    return 0;
}
*/