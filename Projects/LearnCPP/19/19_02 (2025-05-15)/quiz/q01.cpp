// https://www.learncpp.com/cpp-tutorial/dynamically-allocating-arrays

/*
Write a program that:
    Asks the user how many names they wish to enter.
    Dynamically allocates a std::string array.
    Asks the user to enter each name.
    Calls std::sort to sort the names (See 18.1 -- Sorting an array using selection sort and 17.9 -- Pointer arithmetic and subscripting)
    Prints the sorted list of names.
std::string supports comparing strings via the comparison operators < and >. You don’t need to implement string comparison by hand.
Your output should match this:

```
How many names would you like to enter? 5
Enter name #1: Jason
Enter name #2: Mark
Enter name #3: Bob
Enter name #4: Chris
Enter name #5: John

Here is your sorted list:
Name #1: Bob
Name #2: Chris
Name #3: Jason
Name #4: John
Name #5: Mark
```

A reminder
You can use std::getline() to read in names that contain spaces (see lesson 5.7 -- Introduction to std::string).

A reminder
To use std::sort() with a pointer to an array, calculate begin and end manually

```
std::sort(array, array + arrayLength);
```
*/

#include <algorithm>    // std::sort
#include <cstddef>
#include <iostream>
#include <string>

std::size_t getNameCount() {
    std::cout << "How many names would you like to enter? ";
    std::size_t length {};
    std::cin >> length;

    return length;
}

// Asks user to enter all the names
void getNames(std::string* names, std::size_t length) {
    for (std::size_t i { 0 }; i < length; ++i) {
        std::cout << "Enter name #" << i + 1 << ": ";
        std::getline(std::cin >> std::ws, names[i]);
    }
}

// Prints the sorted names
void printNames(std::string* names, std::size_t length) {
    std::cout << "\nHere is your sorted list:\n";
    
    for (std::size_t i { 0 }; i < length; ++i)
        std::cout << "Name #" << i + 1 << ": " << names[i] << '\n';
}

int main() {
    std::size_t length { getNameCount() };

    // Allocate an array to hold the names
    auto* names { new std::string[length] {} };

    getNames(names, length);

    // Sort the array
    std::sort(names, names + length);

    printNames(names, length);

    // don't forget to use array delete
    delete[] names;
    // we don't need to set name sto nullptr/0 here because it's going to go out
    // of scope immediately after this anyway

    return 0;
}