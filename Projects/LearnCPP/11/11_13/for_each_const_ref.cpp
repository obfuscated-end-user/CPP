// https://www.learncpp.com/cpp-tutorial/for-each-loops

#include <iostream>

int main() {
    std::string array[]{ "peter", "likes", "frozen", "yogurt" };
    for (const auto& element: array) { // element is a const reference to the currently iterated array element
        std::cout << element << ' ';
    }

    return 0;
}