// https://www.learncpp.com/cpp-tutorial/for-each-loops/

#include <iostream>

int main() {
    std::string array[]{ "peter", "likes", "frozen", "yogurt" };
    for (auto& element: array) { // The ampersand makes element a reference to the actual array element, preventing a copy from being made
        std::cout << element << ' ';
    }

    return 0;
}