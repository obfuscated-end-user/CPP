// https://www.learncpp.com/cpp-tutorial/assert-and-static_assert/

#include <cassert> // for assert()
#include <cmath> // for std::sqrt
#include <iostream>

double calculateTimeUntilObjectHitsGround(double initialHeight, double gravity) {
    // assert() fucks your function up if it evaluates to false
    assert(gravity > 0.0); // The object won't reach the ground unless there is positive gravity.
    if (initialHeight <= 0.0) {
        // The object is already on the ground. Or buried.
        return 0.0;
    }
    return std::sqrt((2.0 * initialHeight) / gravity);
}

int main() {
    // static_assert() is an assertion that is checked at compile-time rather than at runtime,
    // with a failing static_assert causing a compile error.
    // it isn't in any header so no random ass includes needed
    static_assert(sizeof(int) == 4, "int must be 4 bytes");
    // static_assert(sizeof(long) == 8, "long must be 8 bytes"); // this fucks up your program

    std::cout << "Took " << calculateTimeUntilObjectHitsGround(100.0, -9.8) << " second(s)\n";
    std::cout << "ballsack\n";  // this never gets printed
    return 0;
}