// https://www.learncpp.com/cpp-tutorial/arrays-and-loops

/*
Question #1

Print the following array to the screen using a loop:

constexpr int array[]{ 4, 6, 7, 3, 8, 2, 1, 9, 5 };

Hint: You can use std::size (as of C++17) or the sizeof() trick (prior to C++17) to determine the array length.
*/

#include <iostream>
#include <iterator>

int main() {
    constexpr int array[]{ 4, 6, 7, 3, 8, 2, 1, 9, 5 };
    constexpr int arraySize = std::size(array) - 1;

    std::cout << '[';
    for (int i = 0; i <= arraySize; ++i) {
        if (i < arraySize)
            std::cout << array[i] << ", ";
        else
            std::cout << array[i];
    }
    std::cout << ']';

    return 0;
}

/*
#include <iostream>
#include <iterator> // for std::size

int main()
{
    constexpr int array[]{ 4, 6, 7, 3, 8, 2, 1, 9, 5 };

    for (int index{ 0 }; index < static_cast<int>(std::size(array)); ++index)
    {
        std::cout << array[index] << ' ';
    }

    std::cout << '\n';

    return 0;
}
*/