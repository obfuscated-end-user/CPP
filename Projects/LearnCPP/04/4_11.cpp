// https://www.learncpp.com/cpp-tutorial/chars/

#include <iostream>

int main() {
    // char ass = {'死'}; // fucks up the program
    char ass = {'死'}; // fucks up the program
    std::cout << ass << "\n\n";

    std::cout << "Input a keyboard character: "; // assume the user enters "abcd" (without quotes)
    char ch{};
    std::cin >> ch; // ch = 'a', "bcd" is left queued.
    std::cout << "You entered: " << ch << '\n';
    // Note: The following cin doesn't ask the user for input, it grabs queued input!
    // it does that because it is of char type, not a string type (which will save all the shit you typed into a variable)
    std::cin >> ch; // ch = 'b', "cd" is left queued.
    std::cout << "You entered: " << ch << '\n';

    return 0;
}