// https://www.learncpp.com/cpp-tutorial/return-by-reference-and-return-by-address

#include <iostream>
#include <string>

const std::string& getProgramName() { // will return a const reference
    const std::string programName{ "Calculator" };

    return programName;
}

int main() {
    std::string name { getProgramName() }; // makes a copy of a dangling reference
    std::cout << "This program is named " << name; // undefined behavior

    return 0;
}