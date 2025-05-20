// https://www.learncpp.com/cpp-tutorial/lambda-captures

/*
What does the following code print? Don’t run the code, work it out in your head.
*/

#include <iostream>
#include <string>

int main() {
    std::string favoriteFruit { "grapes" };

    auto printFavoriteFruit {
        [=]() {
            std::cout << "I like " << favoriteFruit << '\n';
        }
    };

    favoriteFruit = "bananas with chocolate";

    printFavoriteFruit();

    return 0;
}