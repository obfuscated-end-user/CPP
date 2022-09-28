#include <random>
#include <iostream>

// unfinished
int main() {
    static std::mt19937 mt { static_cast<std::mt19937::result_type>(std::time(nullptr)) }; // can't use operator= here

    auto shit = std::uniform_int_distribution {min, max}(mt);
    return 0;
}