// https://www.learncpp.com/cpp-tutorial/chapter-12-comprehensive-quiz/

// hey, i copied the code over from the site. i can't fucking do anything practical. i can't think like a programmer.

#include <iostream>
#include <iterator>
#include <cassert>
#include <numeric>  // for std::midpoint. GO FUCK YOURSELF

// array is the array to search over.
// target is the value we're trying to determine exists or not.
// min is the index of the lower bounds of the array we're searching.
// max is the index of the upper bounds of the array we're searching.
// binarySearch() should return the index of the target element if the target is found, -1 otherwise
int binarySearch(const int* array, int target, int min, int max) {
    assert(array);  // make sure array exists

    // while min is less than or equal to max
    while (min <= max) {
        // implement this iteratively
        // int midpoint = std::midpoint(min, max);  // this doesn't work for me, even though i had set my version to C++20. i don't know what the fuck happened.
        // Before C++20
        int midpoint = min + ((max - min) / 2); // this way of calculating midpoint avoids overflow

        if (array[midpoint] > target) {
            // if array[midpoint] > target, then we know the number must be in the lower half of the array
            // we can use midpoint - 1 as the upper index, since we don't need to retest the midpoint next iteration
            // own words: if the value at the midpoint is larger than the target, then it's no use searching on the right side of the array, the right side of the midpoint.
            std::cout << "value at midpoint larger than target\n";
            max = midpoint - 1;
        } else if (array[midpoint] < target) {
            // if array[midpoint] < target, then we know the number must be in the upper half of the array.
            // we can use midpoint + 1 as the lower index, since we don't need to retest the midpoint next iteration
            // own words: if the value at the midpoint is smaller than the target, then it's no use searching on the left side of the array, the left side of the midpoint.
            std::cout << "value at midpoint smaller than target\n";
            min = midpoint + 1;
        } else {
            // if you haven't noticed already, the lines "max = midpoint - 1;" and "min = midpoint + 1;" prevent this from becoming an infinite loop. it modifies those values until it eventually leads here.
            // ^ false. dumbass misconception.
            std::cout << "returning midpoint\n";
            return midpoint;
        }
    }

    return -1;
}

int main() {
    constexpr int array[] {3, 6, 8, 12, 14, 17, 20, 21, 26, 32, 36, 37, 42, 44, 48};
    // We're going to test a bunch of values to see if they produce the expected results
    constexpr int numTestValues = 9;
    // Here are the test values
    constexpr int testValues[numTestValues] {0, 3, 12, 13, 22, 26, 43, 44, 49};
    // And here are the expected results for each value
    int expectedValues[numTestValues] {-1, 0, 3, -1, -1, 8, -1, 13, -1};

    // Loop through all of the test values
    for (int count = 0; count < numTestValues; ++count) {
        // See if our test value is in the array
        int index = binarySearch(array, testValues[count], 0, static_cast<int>(std::size(array)) - 1);
        // If it matches our expected value, then great!
        if (index == expectedValues[count])
            std::cout << "test value " << testValues[count] << " passed!\n";
        else    // otherwise, our binarySearch() function must be broken
            std::cout << "test value " << testValues[count] << " failed. There's something wrong with your code!n";
    }

    return 0;
}