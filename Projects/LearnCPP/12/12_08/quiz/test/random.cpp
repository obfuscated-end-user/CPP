#include <random>
#include <ctime>
#include <iostream>

// unfinished
int main() {
    std::mt19937 random1(std::time(nullptr));   // system time is used because it always changes
    std::cout << random1() << '\n';  // printing this without the paretheses will break your terminal

    std::mt19937 random2(1);
    std::cout << random2() << '\n';  // a constant will always produce the same number. in this case, passing 1 will give back the number 1791095845

    // using a for loop
    std::mt19937 random3(std::time(nullptr)); 
    for (int i  = 0; i < 10; ++i) {
        std::cout << random3() << ' ';
    }
    std::cout << '\n';

    // using a for loop, but seed is 1
    std::mt19937 random4(1); 
    for (int i  = 0; i < 10; ++i) {
        // 1791095845 4282876139 3093770124 4005303368 491263 550290313 1298508491 4290846341 630311759 1013994432
        std::cout << random4() << ' ';
    }

    return 0;
}