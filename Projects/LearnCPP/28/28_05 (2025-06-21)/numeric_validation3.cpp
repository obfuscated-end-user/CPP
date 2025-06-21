// https://www.learncpp.com/cpp-tutorial/stream-states-and-input-validation

#include <charconv> // std::from_chars
#include <iostream>
#include <limits>
#include <optional>
#include <string>
#include <string_view>

// std::optional<int> returns either an int or nothing
std::optional<int> extractAge(std::string_view age) {
    int result {};
    const auto end { age.data() + age.length() };   // get end iterator of underlying C-style string

    // Try to parse an int from age
    // If we got an error of some kind...
    if (std::from_chars(age.data(), end, result).ec != std::errc {}) {
        return {};  // return nothing
    }

    if (result <= 0) {  // make sure age is positive
        return {};      // return nothing
    }

    return result; // return an int value
}

int main() {
    int age {};

    while (true) {
        std::cout << "Enter your age: ";
        std::string strAge {};

        // Try to get a line of input
        if (!std::getline(std::cin >> std::ws, strAge)) {
            // If we failed, clean up and try again
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        // Try to extract the age
        auto extracted { extractAge(strAge) };

        // If we failed, try again
        if (!extracted)
            continue;

        age = *extracted;   // get the value
        break;
    }

    std::cout << "You entered: " << age << '\n';

    return 0;
}