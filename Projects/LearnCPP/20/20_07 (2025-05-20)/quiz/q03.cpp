// https://www.learncpp.com/cpp-tutorial/lambda-captures

/*
We’re going to write a little game with square numbers (numbers which can be created by multiplying an integer with itself (1, 4, 9, 16, 25, …)).

To setup the game:
	Ask the user to enter a number to start at (e.g. 3).
	Ask the user how many values to generate.
	Pick a random integer between 2 and 4. This is the multiplier.
	Generate the number of values the user indicated. Begining with the starting number, each value should be the next square number, multiplied by the multiplier.

To play the game:
	The user enters a guess.
	If the guess matches any generated value, the value is removed from the list and the user gets to guess again.
	If the user guesses all of the generated values, they win.
	If the guess does not match a generated value, the user loses and the program tells them the nearest unguessed value.

Here are a couple of sample sessions to give you a better understanding of how the game works:

```
Start where? 4
How many? 5
I generated 5 square numbers. Do you know what each number is after multiplying it by 2?
> 32
Nice! 4 number(s) left.
> 72
Nice! 3 number(s) left.
> 50
Nice! 2 number(s) left.
> 126
126 is wrong! Try 128 next time.
```

	Starting at 4, the program generates the next 5 squares: 16, 25, 36, 49, 64
	The program picked 2 as the random multiplier, so each square is multiplied by 2: 32, 50, 72, 98, 128
	Now the user gets to guess.
	32 is in the list.
	72 is in the list.
	126 is not in the list, so the user loses. The closest unguessed number is 128.

```
Start where? 1
How many? 3
I generated 3 square numbers. Do you know what each number is after multiplying it by 4?
> 4
Nice! 2 number(s) left.
> 16
Nice! 1 number(s) left.
> 36
Nice! You found all numbers, good job!
```

	Starting at 1, the program generates the next 3 squares: 1, 4, 9
	The program picked 4 as the random multiplier, so each square is multiplied by 4: 4, 16, 36
	The user guesses all numbers correctly and wins the game.

Tips:

	Use Random.h (8.15 -- Global random numbers (Random.h)) to generate random numbers.
	Use std::find() (18.3 -- Introduction to standard library algorithms) to search for a number in the list.
	Use std::vector::erase() to remove an element, e.g.

```
auto found{ std::find(/ ... /) };

// Make sure the element was found

myVector.erase(found);
```

	Use std::min_element and a lambda to find the number closest to the user’s guess. std::min_element works analogous to std::max_element from the previous quiz.

Hint: Use std::abs from <cmath> to calculate the positive difference between two numbers.

```
int distance{ std::abs(3 - 5) }; // 2
```
*/

#include <algorithm>	// std::find, std::min_element
#include <cmath>		// std::abs
#include <cstddef>	  // std::size_t
#include <iostream>
#include <vector>
#include "Random.h"

using Numbers = std::vector<int>;

namespace config {
	constexpr int multiplierMin { 2 };
	constexpr int multiplierMax { 6 };
}

// Generates @count numbers starting at @start*start and multiplies
// every square number by @multiplier
Numbers generateNumbers(int start, int count, int multiplier) {
	Numbers numbers(static_cast<std::size_t>(count));

	for (int index = 0; index < count; ++index) {
		std::size_t uindex { static_cast<std::size_t>(index) };
		numbers[uindex] = (start + index) * (start + index) * multiplier;
	}

	return numbers;
}

// Asks the user to input starting number, then generates array of numbers
Numbers setupGame() {
	int start {};
	std::cout << "Start where? ";
	std::cin >> start;

	int count {};
	std::cout << "How many? ";
	std::cin >> count;

	int multiplier { Random::get(config::multiplierMin, config::multiplierMax) };

	std::cout << "I generated " << count
		<< " square numbers. Do you know what each number is after multiplying it by "
		<< multiplier << '\n';
	
	return generateNumbers(start, count, multiplier);
}

// Returns the user's guess
int getUserGuess() {
	int guess {};

	std::cout << "> ";
	std::cin >> guess;

	return guess;
}

// Searches for the value @guess in @numbers and removes it.
// Returns true if the value was found. False otherwise.
bool findAndRemove(Numbers& numbers, int guess) {
	auto found { std::find(numbers.begin(), numbers.end(), guess) };

	if (found == numbers.end())
		return false;

	numbers.erase(found);
	return true;
}

// Finds the value in @numbers that is closest to @guess.
int findClosestNumber(const Numbers& numbers, int guess) {
	return *std::min_element(numbers.begin(), numbers.end(),
		[=](int a, int b) {
			return std::abs(a - guess) < std::abs(b - guess);
		}
	);
}

// Called when the user guesses a number correctly.
void printSuccess(const Numbers& numbers) {
	std::cout << "Nice! ";

	if (numbers.size() == 0) {
		std::cout << "You found all numbers, good job!\n";
	} else {
		std::cout << numbers.size() << " number(s) left.\n";
	}
}

// Called when the user guesses a number that is not in the numbers.
void printFailure(const Numbers& numbers, int guess) {
	int closest { findClosestNumber(numbers, guess) };

	std::cout << guess << " is wrong!\n";

	std::cout << "Try: " << closest << " next time.\n";
}

int main() {
	Numbers numbers { setupGame() };

	while (true) {
		int guess { getUserGuess() };

		if (!findAndRemove(numbers, guess)) {
			printFailure(numbers, guess);
			break;
		}

		printSuccess(numbers);
		if (numbers.size() == 0)
			break;
	}


	return 0;
}