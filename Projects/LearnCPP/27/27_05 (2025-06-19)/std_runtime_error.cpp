// https://www.learncpp.com/cpp-tutorial/exceptions-classes-and-inheritance

#include <exception>    // for std::exception
#include <iostream>
#include <stdexcept>    // for std::runtime_error

int main() {
    try {
        throw std::runtime_error("Bad things happened");
    } catch (const std::exception& exception) {
        // This handler will catch std::exception and all the derived exceptions too
        std::cerr << "Standard exception: " << exception.what() << '\n';
    }

    return 0;
}