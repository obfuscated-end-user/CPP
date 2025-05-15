// https://www.learncpp.com/cpp-tutorial/sorting-an-array-using-selection-sort

/*
Rewrite the selection sort code above to sort in descending order (largest numbers first). Although this may seem complex, it is actually surprisingly simple.
*/

/*
Simply change:

```
if (array[currentIndex] < array[smallestIndex])
```

to:

```
if (array[currentIndex] > array[smallestIndex])
```

smallestIndex should probably be renamed largestIndex as well.
*/

#include <iostream>
#include <iterator>
#include <utility>

int main() {
    int array[] { 30, 50, 20, 10, 40 };
    constexpr int length { static_cast<int>(std::size(array)) };    // C++17
//  constexpr int length { sizeof(array) / sizeof(array[0]) };  // use instead if not C++17 capable

    // Step through each element of the array the last
    for (int startIndex { 0 }; startIndex < length - 1; ++startIndex) {
        // largestIndex is the index of the largest element we've encountered so far.
        int largestIndex { startIndex };

        // Search through every element starting at startIndex + 1
        for (int currentIndex { startIndex + 1 }; currentIndex < length; ++ currentIndex) {
            // If the current element is larger than our previously found largest
            if (array[currentIndex] > array[largestIndex])
                // This is the new largest number for this iteration
                largestIndex = currentIndex;
        }

        // Swap our start element with our largest element
        std::swap(array[startIndex], array[largestIndex]);
    }

    // Now print our sorted array as proof it works
    for (int index { 0 }; index < length; ++index)
        std::cout << array[index] << ' ';

    std::cout << '\n';

    return 0;
}