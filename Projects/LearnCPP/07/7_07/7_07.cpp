// https://www.learncpp.com/cpp-tutorial/intro-to-loops-and-while-statements

#include <iostream>

int main() {
    int count{ 1 };
    while (count <= 10) {
        std::cout << count << ' ';
        ++count;
    }
    std::cout << "done!";

    while (true) { // infinite loop
        std::cout << "Loop again (y/n)? ";
        char c{};
        std::cin >> c;
        if (c == 'n')
            return 0;
    }
    return 0;
}