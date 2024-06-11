// https://www.learncpp.com/cpp-tutorial/for-each-loops

/*
This one should be easy.

Question #1

Declare a fixed array with the following names: Alex, Betty, Caroline, Dave, Emily, Fred, Greg, and Holly. Ask the user to enter a name. Use a for each loop to see if the name the user entered is in the array.

Sample output:

Enter a name: Betty
Betty was found.

Enter a name: Megatron
Megatron was not found.

Hint: Use std::string_view as your array type.
*/

#include <iostream>
#include <string_view>

int main() {
    std::string_view names[]{ "Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly" };

    std::cout << "Enter a name: ";
    std::string enteredName;
    std::cin >> enteredName;

    bool found {false};

    for (auto& name : names) {
        if (enteredName == name) {
            std::cout << name << " was found.";
            found = true;
        }
    }

    if (!found)
        std::cout << enteredName << " was not found.";

    return 0;
}