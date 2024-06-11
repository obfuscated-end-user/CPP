// https://www.learncpp.com/cpp-tutorial/arrays-and-loops

#include <iostream>
#include <iterator>

int main() {
    constexpr int scores[]{ 84, 92, 76, 81, 56 };
    constexpr int numStudents{ static_cast<int>(std::size(scores)) };   // 5. but the array is indexed from 0 to 4.

    int maxScore{ 0 }; // keep track of our largest score
    for (int student{ 0 }; student <= numStudents; ++student) {
        if (scores[student] > maxScore) {   // scores[5] > maxScore = ???
            maxScore = scores[student];
        }
    }

    std::cout << "The best score was " << maxScore << '\n';

    return 0;
}