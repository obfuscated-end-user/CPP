// https://www.learncpp.com/cpp-tutorial/converting-an-enumeration-to-and-from-a-string

#include <algorithm>
#include <cctype>
#include <iostream>
#include <optional>
#include <string>
#include <string_view>

enum Pet {
    cat,    // 0
    dog,    // 1
    pig,    // 2
    whale,  // 3
};

constexpr std::string_view getPetName(Pet pet) {
    switch (pet) {
        case cat:   return "cat";
        case dog:   return "dog";
        case pig:   return "pig";
        case whale: return "whale";
        default:    return "???";
    }
}

constexpr std::optional<Pet> getPetFromString(std::string_view sv) {
    if (sv == "cat")    return cat;
    if (sv == "dog")    return dog;
    if (sv == "pig")    return pig;
    if (sv == "whale")  return whale;

    return {};
}

// This function returns an std::string that is the lower-case version of the std::string_view passed in.
// Only 1.1 character mapping can be performed by this function
std::string toASCIILowerCase(std::string_view sv) {
    std::string lower {};
    std::transform(sv.begin(), sv.end(), std::back_inserter(lower),
        [](unsigned char c){ return static_cast<char>(std::tolower(c)); }
    );

    return lower;
}

int main() {
    std::cout << "Enter a pet: cat, dog, pig, or whale: ";
    std::string s {};
    std::cin >> s;
    // toASCIILowerCase(s);

    std::optional<Pet> pet { getPetFromString(s) };
    if (!pet)
        std::cout << "You entered an invalid pet\n";
    else
        std::cout << "You entered: " << getPetName(*pet) << '\n';

    return 0;
}