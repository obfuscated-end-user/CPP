// https://www.learncpp.com/cpp-tutorial/lambda-captures

/*
Question #3

We’re going to write a little game with square numbers (numbers which can be created by multiplying an integer with itself (1, 4, 9, 16, 25, …)).

Ask the user to input 2 numbers, the first is the square root of the number to start at, the second is the amount of numbers to generate. Generate a random integer from 2 to 4, and square numbers in the range that was chosen by the user. Multiply each square number by the random number. You can assume that the user enters valid numbers.

The user has to calculate which numbers have been generated. The program checks if the user guessed correctly and removes the guessed number from the list. If the user guessed wrong, the game is over and the program prints the number that was closest to the user’s final guess, but only if the final guess was not off by more than 4.

Here are a couple of sample sessions to give you a better understanding of how the game works:

Start where? 4
How many? 8
I generated 8 square numbers. Do you know what each number is after multiplying it by 2?
> 32
Nice! 7 number(s) left.
> 72
Nice! 6 number(s) left.
> 50
Nice! 5 number(s) left.
> 126
126 is wrong! Try 128 next time.

    The user chose to start at 4 and wants to play with 8 numbers.
    Each square number will be multiplied by 2. 2 was randomly chosen by the program.
    The program generates 8 square numbers, starting with 4 as a base:
    16 25 36 49 64 81 100 121
    But each number is multiplied by 2, so we get:
    32 50 72 98 128 162 200 242
    Now the user starts to guess. The order in which the guesses are entered doesn’t matter.
    32 is in the list.
    72 is in the list.
    126 is not in the list, the user loses. There is a number in the list (128) that is not more then 4 away from the user’s guess, so that number is printed.

Start where? 1
How many? 3
I generated 3 square numbers. Do you know what each number is after multiplying it by 4?
> 4
Nice! 2 numbers left.
> 16
Nice! 1 numbers left.
> 36
Nice! You found all numbers, good job!

    The user chose to start at 1 and wants to play with 3 numbers.
    Each square number will be multiplied by 4.
    The program generates these square numbers:
    1 4 9
    Multiplied by 4
    4 16 36
    The user guesses all numbers correctly and wins the game.

Start where? 2
How many? 2
I generated 2 square numbers. Do you know what each number is after multiplying it by 4?
> 21
21 is wrong!

    The user chose to start at 2 and wants to play with 2 numbers.
    Each square number will be multiplied by 4.
    The program generates these numbers:
    16 36
    The user guesses 21 and loses. 21 is not close enough to any of the remaining numbers, so no number is printed.

Use std::find (11.19 -- Introduction to standard library algorithms) to search for a number in the list.
Use std::vector::erase to remove an element, e.g.

auto found{ std::find(...) };

// Make sure the element was found

myVector.erase(found);

Use std::min_element and a lambda to find the number closest to the user’s guess. std::min_element works analogous to std::max_element from the previous quiz.
*/

// There's no way that I can do all of this in one sitting.
// Fortunately, I can just copy the source code from the site and study it by myself.

#include <algorithm>    // std::find, std::min_element
#include <cmath>    // std::abs
#include <ctime>
#include <iostream>
#include <random>
#include <vector>

using Numbers = std::vector<int>;   // so you don't have to type this every time

namespace config {
    constexpr int multiplierMin = 2;
    constexpr int multiplierMax = 4;
    constexpr int maximumWrongAnswer = 4;
}

int getRandomInt(int min, int max) {
    static std::mt19937 mt { static_cast<std::mt19937::result_type>(std::time(nullptr)) }; // can't use operator= here
    // oh, because it's a class
    // you don't know what you're talking about

    return std::uniform_int_distribution {min, max}(mt);
}

// Generates @count numbers starting at @start*@start and multiplies
// every square number by multiplier
// remember that Numbers is std::vector<int>
Numbers generateNumbers (int start, int count, int multiplier) {
    // std::vector<int> numbers(static_cast<std::vector<int>::size_type>(count));
    // make an int vector named numbers that has a count size
    Numbers numbers(static_cast<Numbers::size_type>(count));
    int i = start;

    // for each number in the vector
    for (auto& number : numbers) {
        // square the numbers times the multiplier, which is random
        number = ((i * i) * multiplier);
        // increment to the value of the next number until you reach all values
        ++i;
    }

    return numbers;
}

// Asks the user to input start and amount, then calls @generateNumbers.
Numbers generateUserNumbers(int multiplier) {
    int start, count;

    std::cout << "Start where? ";
    std::cin >> start;

    std::cout << "How many? ";
    std::cin >> count;
    
    // Input validation omitted. ALl functions assume valid input.
    // this function returns an int vector, which in turn is returned from generateNumbers
    return generateNumbers(start, count, multiplier);
}

int getUserGuess() {
    int guess;

    std::cout << "> ";
    std::cin >> guess;

    return guess;
}

// Searches for the value @guess in @numbers and removes it.
// Returns true if the value as found. False otherwise.
bool findAndRemove(Numbers& numbers, int guess) {
    // iterator
    auto found = std::find(numbers.begin(), numbers.end(), guess);

    // if iterator goes to end; "doesn't find anything"
    if (found == numbers.end())
        return false;
    else {
        // i assume that this erases an element at a specified index (or "position"? whatever that means)
        numbers.erase(found);
        return true;
    }
}

// Finds the value in @numbers that is closest to @guess.
int findClosestNumber(const Numbers& numbers, int guess) {
    // min_element() because it is closer to original value than max. use your head
                                                            // lambda used here
    return *std::min_element(numbers.begin(), numbers.end(), [=](int a, int b) {
        // std::abs() is for getting the absolute value
        return (std::abs(a - guess) < std::abs(b - guess));
    });
}

void printTask(Numbers::size_type count, int multiplier) {
    std::cout << "I generated " << count
            << " square numbers. Do you know what each number is after multiplying it by "
            << multiplier << "?\n";
}

// Called when the user guesses a number correctly.
void printSuccess(Numbers::size_type numbersLeft) {
    std::cout << "Nice! ";

    if (numbersLeft == 0)
        std::cout << "You found all numbers, good job!\n";
    else
        std::cout << numbersLeft << " number(s) left.\n";
}

// Called when the user guesses a number that is not int the numbers.
void printFailure(const Numbers& numbers, int guess) {
    int closest = findClosestNumber(numbers, guess);

    std::cout << guess << " is wrong!";

    // if the user's guess is off by at least 4
    if (std::abs(closest - guess) <= config::maximumWrongAnswer)
        std::cout << " Try " << closest << " next time.\n";
    else
        std::cout << '\n';
}

// Returns false if the game is over. True otherwise.
bool playRound(Numbers& numbers) {
    int guess = getUserGuess();

    if (findAndRemove(numbers, guess)) {
        printSuccess(numbers.size());
        return !numbers.empty();
    } else {
        printFailure(numbers, guess);
        return false;
    }        
}

int main() {
    int multiplier = getRandomInt(config::multiplierMin, config::multiplierMax);
    Numbers numbers = generateUserNumbers(multiplier);
    
    printTask(numbers.size(), multiplier);
    
    while (playRound(numbers));

    return 0;
}