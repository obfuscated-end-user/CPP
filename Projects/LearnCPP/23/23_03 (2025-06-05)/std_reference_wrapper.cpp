// https://www.learncpp.com/cpp-tutorial/aggregation

#include <functional>   // std::reference_wrapper
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string tom { "Tom" };
    std::string berta { "Berta" };

    std::vector<std::reference_wrapper<std::string>> names { tom, berta };  // these strings are stored by reference, not value

    // Vector of const references to std::string
    std::vector<std::reference_wrapper<const std::string>> names2 { tom, berta };  // these strings are stored by reference, not value

    std::string jim { "Jim" };

    names.emplace_back(jim);

    for (auto name : names) {
        // Use the get() member function to get the referenced string.
        name.get() += " Beam";
    }

    std::cout << jim << '\n';

    return 0;
}