/*
Given the array in question 1:

Ask the user for a number between 1 and 9. If the user does not enter a number between 1 and 9, repeatedly ask for an integer value until they do. Once they have entered a number between 1 and 9, print the array. Then search the array for the value that the user entered and print the index of that element.

You can test std::cin for invalid input by using the following code:

// if the user entered something invalid
if (std::cin.fail())
{
    std::cin.clear(); // reset any error flags
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore any characters in the input buffer
}

Here is a sample run of this program:

Enter a number between 1 and 9: d
Enter a number between 1 and 9: 6
4 6 7 3 8 2 1 9 5
The number 6 has index 1
*/

#include <iostream>
#include <iterator>
#include <limits>

int askNumber() {
    bool correct = false;
    int result;
    while(!correct) {
        std::cout << "Enter a number between 1 and 9: ";
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void loopArray(const int[]& array) {
    constexpr int arraySize = std::size(array) - 1;
    std::cout << '[';
    for (int i = 0; i <= arraySize; ++i) {
        if (i < arraySize)
            std::cout << array[i] << ", ";
        else
            std::cout << array[i];
    }
    std::cout << ']';
}

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
// FUCK I GIVE UP
#include <iostream>
#include <iterator> // for std::size
#include <limits>

int main()
{
    // First, read in valid input from user
    int number{};
    do
    {
        std::cout << "Enter a number between 1 and 9: ";
        std::cin >> number;

        // if the user entered an invalid character
        if (std::cin.fail())
            std::cin.clear(); // reset any error flags

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore any extra characters in the input buffer (regardless of whether we had an error or not)

    } while (number < 1 || number > 9);

    // Next, print the array
    constexpr int array[]{ 4, 6, 7, 3, 8, 2, 1, 9, 5 };

    for (int index{ 0 }; index < static_cast<int>(std::size(array)); ++index)
    {
        std::cout << array[index] << ' ';
    }

    std::cout << '\n';

    // Then, search the array to find the matching number and print the index
    for (int index{ 0 }; index < static_cast<int>(std::size(array)); ++index)
    {
        if (array[index] == number)
        {
            std::cout <<  "The number " << number << " has index " <<  index << '\n';
            break; // since each # in the array is unique, no need to search rest of array
        }
    }

    return 0;
}
*/