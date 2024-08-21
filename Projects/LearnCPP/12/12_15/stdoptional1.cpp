// https://www.learncpp.com/cpp-tutorial/stdoptional
// https://en.wikipedia.org/wiki/Semipredicate_problem

#include <iostream>
#include <optional>

std::optional<int> doIntDivision(int x, int y){
    if (y == 0)
        return {};
    return x / y;
}

int main() {
    std::optional<int> result1 { doIntDivision(20, 5) };
    if (result1)    // if the function returned a value
        std::cout << "Result 1: " << *result1 << '\n';
    else
        std::cout << "Result 1: failed\n";  // get the value

    std::optional<int> result2 { doIntDivision(5, 0) };
    if (result2)
        std::cout << "Result 2: " << *result2 << '\n';
    else
        std::cout << "Result 2: failed\n";

    std::optional<int> o1 { 5 };            // initialize with a value
    std::optional<int> o2 {};               // initialize with no value
    std::optional<int> o3 { std::nullopt }; // "          "    "  "

    std::cout << *o1;               // dereference to get value stored in o1 (undefined behavior if o1 does not have a value)
    std::cout << o2.value();        // call value() to get value stoted in o2 (throws std::bad_optional_access exception if o2 does not have a value)
    std::cout << o3.value_or(42);   // call value_or() to get value stored in o3 (or value `42` if o3 doesn't have a value)
    
    return 0;
}