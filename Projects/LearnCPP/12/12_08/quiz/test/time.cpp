#include <ctime>
#include <iostream>

int main() {
    std::time_t foo = std::time(nullptr);
    std::cout << foo << '\n';  // time in seconds since epoch, always a different value
    auto fooFormatted1 = std::asctime(std::localtime(&foo));
    std::cout << fooFormatted1 << '\n';    // time in format "Weekday Month dd hh:mm::ss yyyy"
    auto fooFormatted2 = std::localtime(&foo);
    std::cout << fooFormatted2 << '\n';    // memory address

    return 0;
}