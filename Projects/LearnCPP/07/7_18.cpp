// https://www.learncpp.com/cpp-tutorial/introduction-to-random-number-generation/

#include <iostream>

int plusOne() {
    static int state { 3 }; // only initialized the first time this function is called

    // Generate the next number
    ++state;      // first we modify the state
    return state; // then we use the new state to generate the next number in the sequence
}


// For illustrative purposes only, don't use this
unsigned int LCG16() {// our PRNG
    static unsigned int state{ 5323 };

    // Generate the next number
    // Due to our use of large constants and overflow, it would be
    // hard for someone to casually predict what the next number is
    // going to be from the previous one.
    state = 8253729 * state + 2396403; // first we modify the state

    return state % 32768; // then we use the new state to generate the next number in the sequence
}


int main() {
    /* std::cout << plusOne() << '\n';
    std::cout << plusOne() << '\n';
    std::cout << plusOne() << '\n'; */

    // Print 100 random numbers
    for (int count{ 1 }; count <= 100; ++count) {
        std::cout << LCG16() << '\t';

        // If we've printed 10 numbers, start a new row
        if (count % 10 == 0)
            std::cout << '\n';
    }

    return 0;
}