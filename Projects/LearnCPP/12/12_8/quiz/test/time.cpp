#include <ctime>
#include <iostream>

int main() {
    std::time_t shit = std::time(nullptr);
    std::cout << shit << '\n';  // time in seconds since epoch
    auto shitFormatted1 = std::asctime(std::localtime(&shit));
    std::cout << shitFormatted1 << '\n';    // time in format "Weekday Month dd hh:mm::ss yyyy"
    auto shitFormatted2 = std::localtime(&shit);
    std::cout << shitFormatted2 << '\n';    // memory address

    return 0;
}