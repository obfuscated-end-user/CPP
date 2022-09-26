// https://www.learncpp.com/cpp-tutorial/ellipsis-and-why-to-avoid-them/

#include <iostream>
#include <string>
#include <cstdarg>  // needed to use ellipsis

// The ellipsis must be the last parameter
double findAverage(std::string decoder, ...) {
    double sum = 0;

    // We access the ellipsis through a va_list, so let's declare one
    std::va_list list;

    // We initialize the va_list using va_start. The first parameter is
    // the list to initialize. The second parameter is the last non-ellipsis
    // parameter.
    va_start(list, decoder);

    int count = 0;
    // Loop indefinitely
    while (true) {
        char codetype = decoder[count];
        switch (codetype) {
            default:
            case '\0':  //  null character
                // Cleanup the va_list when we're done.
                va_end(list);
                return sum / count;
            case 'i':   // int
                sum += va_arg(list, int);
                ++count;
                break;
            case 'd':   // double
                sum += va_arg(list, double);
                ++count;
                break;
        }
    }
}

int main() {
    std::cout << findAverage("iiiii", 1, 2, 3, 4, 5) << '\n';
    std::cout << findAverage("iiiiii", 1, 2, 3, 4, 5, 6) << '\n';
    std::cout << findAverage("iiddi", 1, 2, 3.5, 4.5, 5) << '\n';
}

// tl;dr fuck all uses of ellipses so you shouldn't use these in your code