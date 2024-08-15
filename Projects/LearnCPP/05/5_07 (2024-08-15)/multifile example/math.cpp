// https://www.learncpp.com/cpp-tutorial/inline-functions-and-variables

#include "pi.h" // will include a copy of pi() here

/* inline double pi() {
    return 3.14159;
} */

double circumference(double radius) {
    return 2.0 * pi() * radius;
}