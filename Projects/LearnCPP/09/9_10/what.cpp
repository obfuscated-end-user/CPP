// https://www.learncpp.com/cpp-tutorial/pass-by-address-part-2

#include <iostream>

// [[maybe_unused]] gets rid of compiler warnings about ptr2 being set but not used
void nullify([[maybe_unused]] int* ptr2) {
    ptr2 = nullptr; // Make the function parameter a null pointer
}

int main() {
    int x{ 5 };
    int* ptr{ &x }; // ptr points to x
    int* ptr2{};

    std::cout << "ptr is " << (ptr ? "non-null\n" : "null\n");
    nullify(ptr);
    std::cout << "ptr is " << (ptr ? "non-null\n" : "null\n");
    std::cout << "ptr is " << (ptr2 ? "non-null\n" : "null\n");

    return 0;
}