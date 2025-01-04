// https://www.learncpp.com/cpp-tutorial/range-based-for-loops-for-each

#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> words { "peter", "likes", "frozen", "yogurt" };

    // allows us to access the array's element without having to make an expensive copy
    for (const auto& word : words)  // word is now a const reference
        std::cout << word << ' ';

    return 0;
}