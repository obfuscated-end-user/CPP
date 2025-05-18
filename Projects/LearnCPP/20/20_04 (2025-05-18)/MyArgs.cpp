// https://www.learncpp.com/cpp-tutorial/command-line-arguments

// Program: MyArgs
#include <iostream>

int main(int argc, char* argv[]) {
    std::cout << "There are " << argc << " arguments:\n";

    // Loop through each argument and print its number and value
    for (int count { 0 }; count < argc; ++count) {
        std::cout << count << ' ' << argv[count] << '\n';
    }

    return 0;
}
// figure out what the command is because damn
// g++ -std=c++20 "MyArgs.cpp" "MyFile.txt" "100" -o "MyArgs"
// .\MyArgs "MyFile.txt" "100" - use this (compile the program first)