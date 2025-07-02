// https://www.learncpp.com/cpp-tutorial/chapter-20-summary-and-quiz

/*
The best algorithm for determining whether a value exists in a sorted array is called binary search.

Binary search works as follows:

	Look at the center element of the array (if the array has an even number of elements, round down).
	If the center element is greater than the target element, discard the top half of the array (or recurse on the bottom half)
	If the center element is less than the target element, discard the bottom half of the array (or recurse on the top half).
	If the center element equals the target element, return the index of the center element.
	If you discard the entire array without finding the target element, return a sentinel that represents “not found” (in this case, we’ll use -1, since it’s an invalid array index).

Because we can throw out half of the array with each iteration, this algorithm is very fast. Even with an array of a million elements, it only takes at most 20 iterations to determine whether a value exists in the array or not! However, it only works on sorted arrays.

Modifying an array (e.g. discarding half the elements in an array) is expensive, so typically we do not modify the array. Instead, we use two integers (min and max) to hold the indices of the minimum and maximum elements of the array that we’re interested in examining.

Let’s look at a sample of how this algorithm works, given an array { 3, 6, 7, 9, 12, 15, 18, 21, 24 }, and a target value of 7. At first, min = 0, max = 8, because we’re searching the whole array (the array is length 9, so the index of the last element is 8).

	Pass 1) We calculate the midpoint of min (0) and max (8), which is 4. Element #4 has value 12, which is larger than our target value. Because the array is sorted, we know that all elements with index equal to or greater than the midpoint (4) must be too large. So we leave min alone, and set max to 3.
	Pass 2) We calculate the midpoint of min (0) and max (3), which is 1. Element #1 has value 6, which is smaller than our target value. Because the array is sorted, we know that all elements with index equal to or lesser than the midpoint (1) must be too small. So we set min to 2, and leave max alone.
	Pass 3) We calculate the midpoint of min (2) and max (3), which is 2. Element #2 has value 7, which is our target value. So we return 2.

In C++20, calculating the midpoint can be done via calling std::midpoint. Prior to C++20, you’ll need to calculate the midpoint yourself -- in this case you can use min + ((max - min) / 2) to avoid overflow (when min and max are both positive).

Given the following code:

```
#include <iostream>
#include <iterator>

// array is the array to search over.
// target is the value we're trying to determine exists or not.
// min is the index of the lower bounds of the array we're searching.
// max is the index of the upper bounds of the array we're searching.
// binarySearch() should return the index of the target element if the target is found, -1 otherwise
int binarySearch(const int* array, int target, int min, int max)
{

}

int main()
{
	constexpr int array[]{ 3, 6, 8, 12, 14, 17, 20, 21, 26, 32, 36, 37, 42, 44, 48 };

	// We're going to test a bunch of values to see if the algorithm returns the result we expect

	// Here are the test values
	constexpr int testValues[]{ 0, 3, 12, 13, 22, 26, 43, 44, 48, 49 };

	// And here are the results that we expect for those test values
	int expectedResult[]{ -1, 0, 3, -1, -1, 8, -1, 13, 14, -1 };

	// Make sure we have the same number of test values and expected results
	static_assert(std::size(testValues) == std::size(expectedResult));

	int numTestValues { std::size(testValues) };
	// Loop through all of the test values
	for (int count{ 0 }; count < numTestValues; ++count)
	{
		// See if our test value is in the array
		int index{ binarySearch(array, testValues[count], 0, static_cast<int>(std::size(array)) - 1) };
		// If it matches our expected value, then great!
		if (index == expectedResult[count])
			 std::cout << "test value " << testValues[count] << " passed!\n";
		else // otherwise, our binarySearch() function must be broken
			 std::cout << "test value " << testValues[count] << " failed.  There's something wrong with your code!\n";
	}

	return 0;
}
```

a) Write an iterative version of the binarySearch function.

Hint: You can safely say the target element doesn’t exist when the min index is greater than the max index.
*/

#include <cassert>
#include <iostream>
#include <numeric>  // for std::midpoint

// array is the array to search over.
// target is the value we're trying to determine exists or not.
// min is the index of the lower bounds of the array we're searching.
// max is the index of the upper bounds of the array we're searching.
// binarySearch() should return the index of the target element if the target is found, -1 otherwise
int binarySearch(const int* array, int target, int min, int max) {
	assert(array);  // make sure array exists

	while (min <= max) {
		// implement this iteratively
		int midpoint { std::midpoint(min, max) };
		// Before C++20
		// int midpoint { min + ((max - min) / 2) };	// this way of calculating midpoint avoids overflow

		if (array[midpoint] > target) {
			// if array[midpoint] > target, then we know the number must be in the lower half of the array
			// we can use midpoint - 1 as the upper index, since we don't need to retest the midpoint next iteration
			max = midpoint - 1;
		} else if (array[midpoint] < target) {
			// if array[midpoint] < target, then we know the number must be in the upper half of the array
			// we can use midpoint + 1 as the lower index, since we don't need to retest the midpoint next iteration
			min = midpoint + 1;
		} else {
			return midpoint;
		}
	}

	return -1;
}

int main() {
	constexpr int array[] { 3, 6, 8, 12, 14, 17, 20, 21, 26, 32, 36, 37, 42, 44, 48 };

	// We're going to test a bunch of values to see if the algorithm returns the result we expect

	// Here are the test values
	constexpr int testValues[] { 0, 3, 12, 13, 22, 26, 43, 44, 48, 49 };

	// And here are the results that we expect for those test values
	int expectedResult[] { -1, 0, 3, -1, -1, 8, -1, 13, 14, -1 };
	
	// Make sure we have the same number of test values and expected results
	static_assert(std::size(testValues) == std::size(expectedResult));

	int numTestValues { std::size(testValues) };
	// Loop through all of the test values
	for (int count { 0 }; count < numTestValues; ++count) {
		// See if our test value is in the array
		int index { binarySearch(array, testValues[count], 0, static_cast<int>(std::size(array)) - 1) };
		// If it matches our expected value, then great!
		if (index == expectedResult[count])
			std::cout << "test value " << testValues[count] << " passed!\n";
		else
			std::cout << "test value " << testValues[count] << " failed. There's something wrong with your code!\n";
	}

	return 0;
}