// https://www.learncpp.com/cpp-tutorial/arrays-and-loops

/*
In the quiz for lesson 8.10 -- For statements, we implemented a game called FizzBuzz for the numbers three, five, and seven.

In this quiz, implement the game as follows:

    Numbers divisible by only 3 should print “fizz”.
    Numbers divisible by only 5 should print “buzz”.
    Numbers divisible by only 7 should print “pop”.
    Numbers divisible by only 11 should print “bang”.
    Numbers divisible by only 13 should print “jazz”.
    Numbers divisible by only 17 should print “pow”.
    Numbers divisible by only 19 should print “boom”.
    Numbers divisible by more than one of the above should print each of the words associated with its divisors.
    Numbers not divisible by any of the above should just print the number.

Use a std::vector to hold the divisors, and another std::vector to hold the words (as type std::string_view). If the arrays do not have the same length, the program should assert. Produce output for 150 numbers.

Hint: Use the sv literal suffix to make the words of type std::string_view, so you can use CTAD to deduce the type of the array.

Hint: Use a nested for-loop to check the number against the divisors. We discuss nested for-loops in lesson 8.10 -- For statements.

Here’s the expected output from the first 21 iterations:

1
2
fizz
4
buzz
fizz
pop
8
fizz
buzz
bang
fizz
jazz
pop
fizzbuzz
16
pow
fizz
boom
buzz
fizzpop
*/

#include <cassert>
#include <iostream>
#include <string_view>
#include <vector>

void fizzbuzz(int count) {
    // We'll make there static so we only have to do initialization once
    static const std::vector divisors { 3, 5, 7, 11, 13, 17, 19 };
    static const std::vector<std::string_view> words { "fizz", "buzz", "pop", "bang", "jazz", "pow", "boom" };
    assert(std::size(divisors) == std::size(words) && "fizzbuzz: array sizes don't match");

    // Loop through each number between 1 and count (inclusive)
    for (int i { 1 }; i <= count; ++i) {
        bool printed { false };

        // Check the current number against each possible divisor
        for (std::size_t j { 0 }; j < divisors.size(); ++j) {
            if (i % divisors[j] == 0) {
                std::cout << words[j];
                printed = true;
            }
        }

        // If there were no divisors
        if (!printed)
            std::cout << i;
        
        std::cout << '\n';
    }
}

int main() {
    fizzbuzz(150);

    return 0;
}