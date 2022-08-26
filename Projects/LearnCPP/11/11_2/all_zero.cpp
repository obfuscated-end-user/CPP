// https://www.learncpp.com/cpp-tutorial/arrays-part-ii/

#include <string>

int main() {
    // Initialize all elements to 0
    int array[5]{ };

    // Initialize all elements to 0.0
    double array[5]{ };

    // Initialize all elements to an empty string
    std::string array[5]{ };

    // uninitialized
    int array[5];

    // uninitialized
    double array[5];

    // Initialize all elements to an empty string
    std::string array[5];

    return 0;
}