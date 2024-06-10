// https://www.learncpp.com/cpp-tutorial/type-deduction-for-objects-using-the-auto-keyword

#include <iostream>
#include <string>
#include <string_view>

int main() {
    auto d{ 5.0 }; // 5.0 is a double literal, so d will be type double
    auto i{ 1 + 2 }; // 1 + 2 evaluates to an int, so i will be type int
    auto x { i }; // i is an int, so x will be type int too
    // auto y; // doesn't work

    using namespace std::literals; // easiest way to access the s and sv suffixes
    auto s1 { "goo"s };  // "goo"s is a std::string literal, so s1 will be deduced as a std::string
    auto s2 { "moo"sv }; // "moo"sv is a std::string_view literal, so s2 will be deduced as a std::string_view
    
    return 0;
}