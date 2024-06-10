// https://www.learncpp.com/cpp-tutorial/switch-statement-basics

#include <iostream>

void printDigitName(int x) {
    switch (x) {
        case 1:
            std::cout << "One";
            return;
        case 2:
            std::cout << "Two";
            return;
        case 3:
            std::cout << "Three";
            return;
        default:
            std::cout << "Unknown";
            return;
    }
}

int main() {
    printDigitName(2);
    return 0;
}