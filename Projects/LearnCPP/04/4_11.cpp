// https://www.learncpp.com/cpp-tutorial/chars

#include <iostream>

int add(int x, int y) {
    return x + y;
}

int main() {
    // char shi = {'死'}; // breaks the program
    // std::cout << shi << "\n\n";

    char invalid { 17 };
    std::cout << invalid << '\n';

    std::cout << "Input a keyboard character: "; // assume the user enters "abcd" (without quotes)
    char ch{};
    std::cin >> ch; // ch = 'a', "bcd" is left queued.
    std::cout << "You entered: " << ch << '\n';
    // Note: The following cin doesn't ask the user for input, it grabs queued input!
    // it does that because it is of char type, not a string type (which will save all the chars you typed into a variable)
    std::cin >> ch; // ch = 'b', "cd" is left queued.
    std::cout << "You entered: " << ch << '\n';

    std::cout << '\a';

    std::cout << add(1, 2) << '/n'; // 312142, wrong newline char

    return 0;
}