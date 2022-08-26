// https://www.learncpp.com/cpp-tutorial/chapter-7-comprehensive-quiz/

/*
Update your previous solution to handle invalid input (e.g. ‘x’) or valid input with extraneous characters (e.g. “43x”) when the user is guessing a number.

Hint: Write a separate function to handle the user inputting their guess (along with the associated error handling).
*/

#include <iostream>
#include <random>
#include <limits>

// i don't know the fucking answer
// answer is on the site itself, just look it up there
// because trying to put it here will fuck up the entire program
bool checkInput(int guess) {
    if (std::cin.fail()) {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.clear();
    }
    /* return std::cin.fail();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); */
}

int main() {
    std::random_device rd;
	std::seed_seq ss{ rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() };
	std::mt19937 mt{ ss };
	std::uniform_int_distribution random_num { 1, 100 };
    int hidden_num = random_num(mt);

    char playAgain = 'y';
    bool again = true;
    while (again) {
        // std::cout << "RANDOM NUMBER: " <<  hidden_num <<'\n'; //debug

        bool answered = false;  // checks if the number is guessed
        int guess;              // the number the user enters
        int guesses = 1;        // number of guesses made by the user
        std::cout << "Let's play a game. I'm thinking of a number. You have 7 tries to guess what it is. " << '\n';
        while (!answered && guesses <= 7) {
            std::cout << "Guess #" << guesses << ": ";
            std::cin >> guess;
            if (static_cast<int>(guess) > hidden_num || checkInput(guess))
                std::cout << "Your guess is too high." << '\n';
            else if ((static_cast<int>(guess) < hidden_num) || checkInput(guess))
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

