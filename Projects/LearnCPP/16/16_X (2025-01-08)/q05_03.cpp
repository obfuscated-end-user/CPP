// https://www.learncpp.com/cpp-tutorial/chapter-16-summary-and-quiz

/*
> Step #3
Now that we can display some game state and get input from the user, let’s integrate that user input into the game.
Goals:
Keep track of which letters the user has guessed.
Display correctly guessed letters.
Implement a basic game loop.
Tasks:
Update the Session class to track which letters have been guessed so far.
Modify the game state function to display both underscores and correctly guessed letters.
Update the input routine to reject letters that have already been guessed.
Write a loop that executes 6 times before quitting (so we can test the above).
In this step, we will not tell the user whether the letter they guessed is in the word (but we will show it as part of the game state display).
The tricky part of this step is deciding how to store information on which letters the user has guessed. There are several different viable ways to do this. A hint: there are a fixed number of letters, and you’re going to be doing this a lot.
Hint: It’s easier and faster to use a bool for each letter than it is to keep a list of letters and have to search that list to determine whether a letter exists.
Hint: It is okay to use std::vector<bool> here since we won’t be using any of the other functionality of the standard library.
Hint: You can convert a letter into an array index via (letter % 32)-1. This works with both lower case and upper case letters.
Here’s sample output for this step:
Welcome to C++man (a variant of Hangman)
To win: guess the word. To lose: run out of pluses.
The word: ________
Enter your next letter: a
The word: ____a___
Enter your next letter: a
You already guessed that. Try again.
Enter your next letter: b
The word: ____a___
Enter your next letter: c
The word: ____a___
Enter your next letter: d
The word: d___a___
Enter your next letter: e
The word: d___a__e
Enter your next letter: f
The word: d___a__e
Enter your next letter: g
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
    std::vector<bool> m_letterGuessed { std::vector<bool>(26) };

    std::size_t toIndex(char c) const {
        return static_cast<std::size_t>((c % 32) - 1);
    }

public:
    std::string_view getWord() const {
        return m_word;
    }

    bool isLetterGuessed(char c) const {
        return m_letterGuessed[toIndex(c)];
    }

    void setLetterGuessed(char c) {
        m_letterGuessed[toIndex(c)] = true;
    }
};

void draw(const Session& s) {
    std::cout << '\n';

    std::cout << "The word: ";
    for (auto c : s.getWord()) {    // step through each letter of the word
        if (s.isLetterGuessed(c))
            std::cout << c;
        else
            std::cout << '_';
    }

    std::cout << '\n';
}

char getGuess(const Session& s) {
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
            continue;
        }

        // Clear out any extraneous input
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // If the user entered an invalid char, try again
        if (c < 'a' || c > 'z') {
            std::cout << "That wasn't a valid input. Try again.\n";
            continue;
        }

        // If the letter was already guessed, try again
        if (s.isLetterGuessed(c)) {
            std::cout << "You already guessed that. Try again.\n";
            continue;
        }

        // If we got here, this must be a valid guess
        return c;
    }
}

int main() {
    std::cout << "Welcome to C++man (a variant of Hangman)\n";
    std::cout << "To win: guess the word.  To lose: run out of pluses.\n";

    Session s {};
    
    int count { 6 };
    while (--count) {
        draw(s);
        char c { getGuess(s) };
        s.setLetterGuessed(c);
    }

    // Draw the final state of the game
    draw(s);

    return 0;
}