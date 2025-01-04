// https://www.learncpp.com/cpp-tutorial/range-based-for-loops-for-each

/*
Modify your solution to quiz 1. In this version, create a function template (not a normal function) called isValueInArray() that takes two parameters: a std::vector, and a value. The function should return true if the value is in the array, and false otherwise. Call the function from main() and pass it the array of names and the name the user entered.
Reminder:
A function template that is using template argument deduction (when template type arguments are not explicitly specified) will not do conversions to match the template type parameters. The call either matches the template (and the template type can be deduced) or it doesn’t.
A function template with an explicitly specified template type argument will convert arguments to match the parameter type (since the type is known).
*/

#include <iostream>
#include <string>
#include <string_view>
#include <vector>

template <typename T>
bool isValueInArray(const std::vector<T>& arr, const T& value) {
    // we'll use a reference since we don't know if T is expensive to copy
    for (const auto& a : arr) {
        if (a == value)
            return true;
    }

    return false;
}

int main() {
    std::vector<std::string_view> names { "Albert", "Betty", "Caroline", "Dave",
        "Emily", "Fred", "Greg", "Holly" };

    std::cout << "Enter a name: ";
    std::string username {};
    std::cin >> username;

    // By explicitly specifying std::string_view as a function template argument,
    // the compiler will implicitly convert username to `std::string_view` to match the parameter type.
    bool found { isValueInArray<std::string_view>(names, username) };

    // The following is also okay. If we rely on template argument deduction instead, the compiler
    // won't do implicit conversions, so we need to make sure `username` has the expected type.
    // bool found { isValueInArray(names, static_cast<std::string_view>(username)) };

    if (found)
        std::cout << username << " was found.\n";
    else
        std::cout << username << " was not found.\n";

    return 0;
}