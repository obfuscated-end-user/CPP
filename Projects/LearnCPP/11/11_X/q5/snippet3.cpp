// https://www.learncpp.com/cpp-tutorial/chapter-11-comprehensive-quiz

/*
Question #5

What’s wrong with each of these snippets, and how would you fix it?

c)

void printArray(int array[])
{
    for (int element : array)
    {
        std::cout << element << ' ';
    }
}

int main()
{
    int array[]{ 9, 7, 5, 3, 1 };

    printArray(array);

    std::cout << '\n';

    return 0;
}
*/

#include <iostream>

void printArray(int array[]) {
    // no iterator
    for (int element : array) {
        std::cout << element << ' ';
    }
}

int main() {
    int array[]{ 9, 7, 5, 3, 1 };

    printArray(array);

    std::cout << '\n';

    return 0;
}

/*
array decays to a pointer when it is passed to printArray(). Range-based for-loops can’t work with a pointer to an array because the size of the array isn’t known. One solution is to add a length parameter to function printArray(), and use a normal for loop. A better solution is to use std::array instead of built-in fixed arrays.
*/