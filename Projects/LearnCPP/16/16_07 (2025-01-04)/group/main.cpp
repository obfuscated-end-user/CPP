// https://www.learncpp.com/cpp-tutorial/arrays-loops-and-sign-challenge-solutions

#include <iostream>
#include <vector>
#include <SignedArrayView.h>

int main() {
    std::vector arr { 9, 7, 5, 3, 1 };
    SignedArrayView sarr { arr };   // Createa a signed view of our std::vector

    for (auto index { sarr.ssize() - 1 }; index >= 0; --index)
        std::cout << sarr[index] << ' ';    // index using a signed type

    return 0;
}