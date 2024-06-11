// https://www.learncpp.com/cpp-tutorial/ellipsis-and-why-to-avoid-them

#include <iostream>
#include <cstdarg>  // needed to use ellipsis, "c standard arguments"

// The ellipsis must be the last parameter
// count is how many additional arguments we're passing
double findAverage(int count, ...) {
    int sum = 0;

    // We access the ellipsis through a va_list, so let's declare one
    std::va_list list;

    // We initialize the va_list using va_start. The first parameter is
    // the list to initialize. The second parameter is the last non-ellipsis
    // parameter.
    va_start(list, count);  // count is the first integer in the argument list if you're still confused

    // Loop through all the ellipsis arguments
    for (int arg = 0; arg < count; ++arg) {
        // We use va_arg to get parameters out of our ellipsis
        // The first parameter is the va_list we're using
        // The second parameter is the type of the parameter
        sum += va_arg(list, int);   // not sure how this knows that there is a next element in the va_list
    }

    // Cleanup the va_list when we're done.
    va_end(list);

    return static_cast<double>(sum) / count;
}

int main() {
    std::cout << findAverage(5, 1, 2, 3, 4, 5) << '\n'; // count is 5
    std::cout << findAverage(6, 1, 2, 3, 4, 5, 6) << '\n';  // count is 6
    std::cout << findAverage(6, 1.0, 2, 3, 4, 5, 6) << '\n';    // what the hell, va_arg() was told that the list only contains ints, but you pass in a double just because
    int value = 7;
    std::cout << findAverage(6, 1.0, 2, "Hello, world!", 'G', &value, &findAverage) << '\n';    // this works. garbage in, garbage out.
    std::cout << findAverage(6, 1, 2, 3, 4, 5) << '\n'; // wrong initial count value, should be 5
    // regarding the count parameter, that means that if you change the first integer argument, you risk messing up the function call
    return 0;
}