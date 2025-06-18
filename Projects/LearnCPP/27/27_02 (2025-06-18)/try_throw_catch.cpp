// https://www.learncpp.com/cpp-tutorial/basic-exception-handling

#include <iostream>
#include <string>

int main() {
    try {
        // Statements that may throw exceptions you want to handle go here
        throw -1;
    } catch (double) {  // no variable name since we don't use the exception itself in the catch block below
        // Any exceptions of type double thrown within the above try block get sent here
        std::cerr << "We caught an exception of type double\n";
    } catch (int x) {
        // Any exceptions of type int thrown within the above try block get sent here
        std::cerr << "We caught an int exception with value: " << x << '\n';
    } catch (std::string&) {
        // Any exceptions of type std::string& thrown within the above try block get sent here
        std::cerr << "We caught an exception of type std::string\n";
    }

    // Execution continues here after the exception has been handled by any of the above catch blocks
    std::cout << "Continuing on our merry way\n";

    return 0;
}