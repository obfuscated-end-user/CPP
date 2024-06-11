// https://www.learncpp.com/cpp-tutorial/lambda-captures

#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>
#include <string>

int main() {
    std::array<std::string_view, 4> arr { "apple", "banana", "walnut", "lemon" };

    std::cout << "search for: ";
    std::string search;
    std::cin >> search;

    // Capture @search                                 vvvvvv
    auto found = std::find_if(arr.begin(), arr.end(), [search](std::string_view str) {
        return (str.find(search) != std::string_view::npos); // search now accessible from this scope
    });

    if (found == arr.end())
        std::cout << "Not found\n";
    else
        std::cout << "Found " << *found << '\n';
        std::cout << "Found " << *(++found) << '\n';    // type "e" and see what happens

    return 0;
}

/*
While it might look like our lambda in the example above is directly accessing the value of main‘s search variable, this is not the case. Lambdas might look like nested blocks, but they work slightly differently (and the distinction is important).

When a lambda definition is executed, for each variable that the lambda captures, a clone of that variable is made (with an identical name) inside the lambda. These cloned variables are initialized from the outer scope variables of the same name at this point.

Thus, in the above example, when the lambda object is created, the lambda gets its own cloned variable named search. This cloned search has the same value as main‘s search, so it behaves like we’re accessing main‘s search, but we’re not.

While these cloned variables have the same name, they don’t necessarily have the same type as the original variable. We’ll explore this in the upcoming sections of this lesson.
*/