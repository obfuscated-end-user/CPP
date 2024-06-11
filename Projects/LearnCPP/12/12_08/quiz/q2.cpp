// https://www.learncpp.com/cpp-tutorial/lambda-captures

/*
Question #2

What does the following code print? Don’t run the code, work it out in your head.
*/

#include <iostream>
#include <string>

int main() {
    std::string favoriteFruit{ "grapes" };

    auto printFavoriteFruit {
        [=]() {
        std::cout << "I like " << favoriteFruit << '\n';
        }
    };

    favoriteFruit = "bananas with chocolate";

    printFavoriteFruit();

    return 0;
}

// i swear i did not run the code pinky promise
// "I like grapes", because the favoriteFruit in the lambda is a copy of the one in main(), so it doesn't modify its value