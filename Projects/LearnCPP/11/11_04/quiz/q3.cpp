// https://www.learncpp.com/cpp-tutorial/sorting-an-array-using-selection-sort

/*
This one is going to be difficult, so put your game face on.

Another simple sort is called “bubble sort”. Bubble sort works by comparing adjacent pairs of elements, and swapping them if the criteria is met, so that elements “bubble” to the end of the array. Although there are quite a few ways to optimize bubble sort, in this quiz we’ll stick with the unoptimized version here because it’s simplest.

Unoptimized bubble sort performs the following steps to sort an array from smallest to largest:
A) Compare array element 0 with array element 1. If element 0 is larger, swap it with element 1.
B) Now do the same for elements 1 and 2, and every subsequent pair of elements until you hit the end of the array. At this point, the last element in the array will be sorted.
C) Repeat the first two steps again until the array is sorted.

Write code that bubble sorts the following array according to the rules above:

int array[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };

Print the sorted array elements at the end of your program.

Hint: If we’re able to sort one element per iteration, that means we’ll need to iterate roughly as many times as there are numbers in our array to guarantee that the whole array is sorted.
Hint: When comparing pairs of elements, be careful of your array’s range.
*/

#include <iostream>
#include <iterator>
#include <utility>

int main() {
    int array[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };
    constexpr int length{ static_cast<int>(std::size(array)) - 1 };

    for (int i = 0; i < length + 1; ++i)
        std::cout << array[i] << ' ';
    std::cout << '\n';

    for (int startIndex = 0; startIndex < length; ++startIndex) {
        for (int smallerIndex = startIndex + 1; smallerIndex < length + startIndex; ++smallerIndex) {
            if (array[startIndex] > array[startIndex + 1])
                std::swap(array[startIndex], array[startIndex + 1]);
        }
    }

    for (int i = 0; i < length + 1; ++i)
        std::cout << array[i] << ' ';
    std::cout << '\n';
    return 0;
}

/*
#include <iostream>
#include <iterator> // for std::size
#include <utility>

int main()
{
    int array[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };
    constexpr int length{ static_cast<int>(std::size(array)) }; // C++17
//  constexpr int length{ sizeof(array) / sizeof(array[0]) }; // use instead if not C++17 capable

    // Step through each element of the array (except the last, which will already be sorted by the time we get to it)
    for (int iteration{ 0 }; iteration < length-1; ++iteration)
    {
        // Search through all elements up to the end of the array - 1
        // The last element has no pair to compare against
        for (int currentIndex{ 0 }; currentIndex < length - 1; ++currentIndex)
        {
            // If the current element is larger than the element after it, swap them
            if (array[currentIndex] > array[currentIndex+1])
                std::swap(array[currentIndex], array[currentIndex + 1]);
        }
    }

    // Now print our sorted array as proof it works
    for (int index{ 0 }; index < length; ++index)
        std::cout << array[index] << ' ';

    std::cout << '\n';

    return 0;
}
*/