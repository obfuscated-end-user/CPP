// https://www.learncpp.com/cpp-tutorial/chapter-16-summary-and-quiz

/*
Let’s implement the game C++man (which will be our version of the classic children’s lynching game Hangman.
In case you’ve never played it before, here are the abbreviated rules:
High level:
The computer will pick a word at random and draw an underscore for each letter in the word.
The player wins if they guess all the letters in the word before making X wrong guesses (where X is configurable).
Each turn:
The player will guess a single letter.
If the player has already guessed that letter, it doesn’t count, and play continues.
If any of the underscores represent that letter, those underscores are replaced with that letter, and play continues.
If no underscores represent that letter, the player uses up one of their wrong guesses.
Status:
The player should know how many wrong guesses they have left.
The player should know what letters they have guessed incorrectly (in alphabetical order).
Because this is C++man, we’ll use a + symbol to indicate the number of wrong guesses left. If you run out of + symbols, you lose.
Here’s sample output from the finished game:
Welcome to C++man (a variant of Hangman)
To win: guess the word. To lose: run out of pluses.
The word: ________ Wrong guesses: ++++++
Enter your next letter: a
No, 'a' is not in the word!
The word: ________ Wrong guesses: +++++a
Enter your next letter: b
Yes, 'b' is in the word!
The word: b_______ Wrong guesses: +++++a
Enter your next letter: c
Yes, 'c' is in the word!
The word: b__cc___ Wrong guesses: +++++a
Enter your next letter: d
No, 'd' is not in the word!
The word: b__cc___ Wrong guesses: ++++ad
Enter your next letter: %
That wasn't a valid input. Try again.
The word: b__cc___ Wrong guesses: ++++ad
Enter your next letter: d
You already guessed that. Try again.
The word: b__cc___ Wrong guesses: ++++ad
Enter your next letter: e
No, 'e' is not in the word!
The word: b__cc___ Wrong guesses: +++ade
Enter your next letter: f
No, 'f' is not in the word!
The word: b__cc___ Wrong guesses: ++adef
Enter your next letter: g
No, 'g' is not in the word!
The word: b__cc___ Wrong guesses: +adefg
Enter your next letter: h
No, 'h' is not in the word!
The word: b__cc___ Wrong guesses: adefgh
You lost! The word was: broccoli

> Step #1
Goals:
We’ll start by defining our list of words and writing a random word picker. You can use the Random.h from lesson 8.15 -- Global random numbers (Random.h) to assist.
Tasks:
First define a namespace named WordList. The starter list of words is: “mystery”, “broccoli” , “account”, “almost”, “spaghetti”, “opinion”, “beautiful”, “distance”, “luggage”. You can add others if you like.
Write a function to pick a random word and display the word picked. Run the program several times to make sure the word is randomized.
Here is a sample output from this step:
Welcome to C++man (a variant of Hangman)
To win: guess the word. To lose: run out of pluses.
The word is: broccoli
*/

#include <iostream>
#include <vector>
#include <Random.h>

namespace WordList {
    // Define your list of words here
    std::vector<std::string_view> words { "mystery", "broccoli" , "account", "almost", "spaghetti", "opinion", "beautiful", "distance", "luggage" };

    std::string_view getRandomWord() {
        return words[Random::get<std::size_t>(0, words.size() - 1)];
    }
}

int main() {
    std::cout << "Welcome to C++man (a variant of Hangman)\n";
    std::cout << "To win: guess the word.  To lose: run out of pluses.\n";

    std::cout << "The word is: " << WordList::getRandomWord();

    return 0;
}