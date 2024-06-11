// https://www.learncpp.com/cpp-tutorial/dynamically-allocating-arrays

/*
Question #1

Write a program that:

    Asks the user how many names they wish to enter.
    Dynamically allocates a std::string array.
    Asks the user to enter each name.
    Calls std::sort to sort the names (See 11.4 -- Sorting an array using selection sort and 11.9 -- Pointer arithmetic and array indexing)
    Prints the sorted list of names.

std::string supports comparing strings via the comparison operators < and >. You don’t need to implement string comparison by hand.

Your output should match this:

How many names would you like to enter? 5
Enter name #1: Jason
Enter name #2: Mark
Enter name #3: Alex
Enter name #4: Chris
Enter name #5: John

Here is your sorted list:
Name #1: Alex
Name #2: Chris
Name #3: Jason
Name #4: John
Name #5: Mark

A reminder

You can use std::getline() to read in names that contain spaces (see lesson 4.17 -- Introduction to std::string).

A reminder

To use std::sort() with a pointer to an array, calculate begin and end manually

std::sort(array, array + arrayLength);
*/

#include <algorithm> // for std::sort
#include <iostream>
#include <string>

int main() {
    int numOfNames;
    std::cout << "How many names would you like to enter? ";
    std::cin >> numOfNames;
    auto* names { new std::string[numOfNames]{} };

    // get names
    for (int i = 0; i < numOfNames; ++i) {
        std::cout << "Name #" << i + 1 << ": ";
        std::cin >> names[i];
    }

    // sort the array
    std::sort(names, names + numOfNames);

    // print the whole array
    std::cout << "Here is your sorted list:\n";
    for (int i = 0; i < numOfNames; ++i)
        std::cout << "Name #" << i + 1 << ": "  << names[i] << '\n';

	return 0;
}