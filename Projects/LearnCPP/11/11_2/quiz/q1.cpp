// https://www.learncpp.com/cpp-tutorial/arrays-part-ii/

/*
Declare an array to hold the high temperature (to the nearest tenth of a degree) for each day of a year (assume 365 days in a year). Initialize the array with a value of 0.0 for each day.
*/

#include <iterator>

int main() {
    double temperature[] = {};
    constexpr int year = 365;
    for (int i = 0; i < year; ++i) {
        temperature[i] = 0.0;
    }

    return 0;
}

/*
answer:
double temperature[365] { };
// WHAT THE FUCK I THOUGHT DO A LONG ASS PROGRAM
*/