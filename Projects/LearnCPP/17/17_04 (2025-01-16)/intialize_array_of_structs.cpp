// https://www.learncpp.com/cpp-tutorial/stdarray-of-class-types-and-brace-elision

#include <array>
#include <iostream>

struct House {
    int number{};
    int stories{};
    int roomsPerStory{};
};

int main() {
    /* constexpr std::array houses {
        House { 13, 1, 7 },
        House { 14, 2, 5 },
        House { 15, 2, 4 }
    }; */

    // This works as expected
    constexpr std::array<House, 3> houses { // intializer for houses
        {   // extra set of braces to intialize the C-style array member with implementatio_defined_name
            { 13, 4, 30 },  // intializer for array element 0
            { 14, 3, 10 },  // intializer for array element 1
            { 15, 3, 40 }   // intializer for array element 2
        }
    };
    
    for (const auto& house : houses) {
        std::cout << "House number " << house.number
                  << " has " << (house.stories * house.roomsPerStory)
                  << " rooms.\n";
    }

    return 0;
}