// https://www.learncpp.com/cpp-tutorial/arrays-and-loops

#include <iostream>
#include <vector>

int main() {
    std::vector testScore { 84, 92, 76, 81, 56 };
    std::size_t length { testScore.size() };

    int average { 0 };
    for (std::size_t index { 0 }; index < length; ++index)
        average += testScore[index];
    average /= static_cast<int>(length);

    std::cout << "The class average is: " << average << '\n';

    return 0;
}