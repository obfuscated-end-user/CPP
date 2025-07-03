// https://www.learncpp.com/cpp-tutorial/chapter-16-summary-and-quiz

/*
> Step #2
As we develop complex programs, we want to work incrementally, adding one or two things at a time and then making sure they work. What makes sense to add next?
Goals:
Be able to draw the basic state of the game, showing the word as underscores.
Accept a letter of input from the user, with basic error validation.
In this step, we will not yet keep track of which letters the user has entered.
Here is the sample output from this step:
Welcome to C++man (a variant of Hangman)
To win: guess the word. To lose: run out of pluses.
The word: ________
Enter your next letter: %
That wasn't a valid input. Try again.
Enter your next letter: a
You entered: a
Tasks:
Create a class named Session that will be used to store all of the data the game needs to manage in a game session. For now, we just need to know what the random word is.
Create a function to display the basic state of the game, where the word is displayed as underscores.
Create a function to accept a letter of input from the user. Do basic input validation to filter out non-letters or extraneous input.
*/

#include <iostream>
#include <string_view>
#include <vector>
#include <Random.h>

namespace WordList {
	// Define your list of words here
	std::vector<std::string_view> words { "mystery", "broccoli" , "account", "almost", "spaghetti", "opinion", "beautiful", "distance", "luggage" };

	std::string_view getRandomWord() {
		return words[Random::get<std::size_t>(0, words.size() - 1)];
	}
}

class Session {
private:
	// Game session data
	std::string_view m_word { WordList::getRandomWord() };

public:
	std::string_view getWord() const {
		return m_word;
	}
};

void draw(const Session& s) {
	std::cout << '\n';

	std::cout << "The word: ";
	for ([[maybe_unused]] auto c : s.getWord()) // step through each letter of the word
		std::cout << '_';

	std::cout << '\n';
}

char getGuess() {
	while (true) {
		std::cout << "Enter your next letter: ";

		char c {};
		std::cin >> c;

		// If user did something bad, try again
		if (!std::cin) {
			// Fix it
			std::cin.clear();
			std::cout << "That wasn't a valid input. Try again.\n";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		// Clear out any extraneous input
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		// If the user entered an invalid char, try again
		if (c < 'a' || c > 'z') {
			std::cout << "That wasn't a valid input. Try again.\n";
			continue;
		}

		return c;
	}
}

int main() {
	std::cout << "Welcome to C++man (a variant of Hangman)\n";
	std::cout << "To win: guess the word.	To lose: run out of pluses.\n";

	Session s {};

	draw(s);
	char c { getGuess() };
	std::cout << "You guessed: " << c << '\n';

	return 0;
}