// https://www.learncpp.com/cpp-tutorial/aggregation

#include <functional>   // std::reference_wrapper
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string tom = "Tom";
    std::string berta = "Berta";

    // these strings are stored by reference, not value;
    std::vector<std::reference_wrapper<std::string>> names {tom, berta};
    // since you can't do something like:
    // std::vector<std::string&> names {tom, berta};
    // std::vector<int&> numbers {1, 2, 3};

    // To create a vector of const references, we'd have to add const before the std::string like so:
    // std::vector<std::reference_wrapper<const std::string>> names {tom, berta};

    std::string jim = "Jim";
    std::cout << jim << '\n';

    names.push_back(jim);

    for (auto name : names)
        // use get() to get the referenced string
        name.get() += " Beam";

    std::cout << jim << '\n';

    return 0;
}