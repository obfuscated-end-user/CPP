// facebook.com

#include <iostream>
#include <limits>

int max(int x, int y) {
    return (x > y) ? x : y;
}

// doesn't work
/* int max(int x, int y)
    return (x > y) ? x : y; */

int main() {
    /* std::int32_t foo = 29919012040989911489310790;
    std::cout << foo << " " << sizeof(foo) << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.fail(); */
    int x;
    std::cout << "Enter something: ";
    std::cin >> x;
    // std::cout << x;
    if (static_cast<int>(x) == 0)
        std::cout << "ass";

    int i { 3.5 }; // won't compile
    return 0;
}