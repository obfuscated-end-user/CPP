// NOT MINE
// source: https://www.freecodecamp.org/news/search-algorithms-exponential-search-explained

// C++ program to find an element x in a
// sorted array using Exponential search.
#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int, int, int);

// Returns position of first ocurrence of
// x in array
int exponentialSearch(int arr[], int n, int x)
{
    // If x is present at firt location itself
    if (arr[0] == x)
        return 0;

    // Find range for binary search by
    // repeated doubling
    int i = 1; // variable used for array index
    while (i < n && arr[i] <= x) // if array index is less than array size AND value at array[i] is less than or equal than desired value
        i = i*2; // increment i by raising it to the power of two

    //  Call binary search for the found range.
    return binarySearch(arr, i/2, min(i, n), x);
}

// A recursive binary search function. It returns
// location of x in  given array arr[l..r] is
// present, otherwise -1
int binarySearch(int arr[], int l, int r, int x)
{
    /*
        arr[] = array to be used for searching
        l = left half of the array
        r = right half of the array
        x = value to look for
    */
    if (r >= l)
    {
        int mid = l + (r - l)/2;

        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;

        // If element is smaller than mid, then it
        // can only be present n left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid-1, x);

        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid+1, r, x);
    }

    // We reach here when element is not present
    // in array
    return -1;
}

int main(void)
{
    int arr[] = {2, 3, 4, 10, 40}; // array to be used for searching
    int n = sizeof(arr); // array size, used to have something like "/ sizeof(arr[0])" on it (slash included)
    int x = 0; // element to be looked for in the array
    int result = exponentialSearch(arr, n, x);
    (result == -1)? printf("Element is not present in array"): printf("Element is present at index %d", result);
    return 0;
}