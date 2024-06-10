// https://www.learncpp.com/cpp-tutorial/chapter-7-comprehensive-quiz

/*
Implement a game of hi-lo. First, your program should pick a random integer between 1 and 100. The user is given 7 tries to guess the number.

If the user does not guess the correct number, the program should tell them whether they guessed too high or too low. If the user guesses the right number, the program should tell them they won. If they run out of guesses, the program should tell them they lost, and what the correct number is. At the end of the game, the user should be asked if they want to play again. If the user doesn’t enter ‘y’ or ‘n’, ask them again.

For this quiz, assume the user enters a valid number. Use a Mersenne Twister PRNG, and seed it using a std::seed_seq with 8 results from std::random_device. See lesson 7.19 -- Generating random numbers using Mersenne Twister for more details.

Here’s what your output should look like:

Let's play a game. I'm thinking of a number. You have 7 tries to guess what it is.
Guess #1: 64
Your guess is too high.
Guess #2: 32
Your guess is too low.
Guess #3: 54
Your guess is too high.
Guess #4: 51
Correct! You win!
Would you like to play again (y/n)? y
Let's play a game. I'm thinking of a number. You have 7 tries to guess what it is.
Guess #1: 64
Your guess is too high.
Guess #2: 32
Your guess is too low.
Guess #3: 54
Your guess is too high.
Guess #4: 51
Your guess is too high.
Guess #5: 36
Your guess is too low.
Guess #6: 45
Your guess is too low.
Guess #7: 48
Your guess is too low.
Sorry, you lose. The correct number was 49.
Would you like to play again (y/n)? q
Would you like to play again (y/n)? n
Thank you for playing.
*/

#include <iostream>
#include <random>

int main() {
    std::random_device rd;
	std::seed_seq ss{ rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() };
	std::mt19937 mt{ ss };
	std::uniform_int_distribution random_num { 1, 100 };
    int hidden_num = random_num(mt);

    char playAgain = 'y';
    bool again = true;
    while (again) {
        // std::cout << "RANDOM NUMBER:" <<  hidden_num <<'\n'; //debug

        bool answered = false;  // checks if the number is guessed
        int guess;              // the number the user enters
        int guesses = 1;        // number of guesses made by the user
        std::cout << "Let's play a game. I'm thinking of a number. You have 7 tries to guess what it is. " << '\n';
        while (!answered && guesses <= 7) {
            std::cout << "Guess #" << guesses << ": ";
            std::cin >> guess;
            if (static_cast<int>(guess) > hidden_num)
                std::cout << "Your guess is too high." << '\n';
            else if (static_cast<int>(guess) < hidden_num)
                std::cout << "Your guess is too low." << '\n';
            else {
                std::cout << "Correct! You win!" << '\n';
                answered = true;
            }
            ++guesses;
        }
        if (!answered) // if true
            std::cout << "Sorry, you lose. The correct number was " << hidden_num << ".\n";

        std::cout << "Would you like to play again (y\\n)? ";
        std::cin >> playAgain;
        again = (playAgain == 'y') || (playAgain == 'Y') ? true : false;
        hidden_num = random_num(mt); // reset hidden number
    }
    std::cout << "Thank you for playing.";
    return 0;
}

