// https://www.learncpp.com/cpp-tutorial/chapter-11-comprehensive-quiz

/*
Question #5

What’s wrong with each of these snippets, and how would you fix it?

a)

int main()
{
    int array[]{ 0, 1, 2, 3 };

    for (std::size_t count{ 0 }; count <= std::size(array); ++count)
    {
    std::cout << array[count] << ' ';
    }

    std::cout << '\n';

    return 0;
}
*/

#include <iostream>

int main() {
    int array[]{ 0, 1, 2, 3 };

    // size_t is unsigned int, std::size returns the size of array, so you need to subtract 1 from it
    for (std::size_t count{ 0 }; count <= std::size(array) - 1; ++count) {
        std::cout << array[count] << ' ';
    }

    std::cout << '\n';

    return 0;
}

/*
The loop has an off-by-one error, and tries to access the array element with index 4, which does not exist. The conditional in the for loop should use < instead of <=.
*/