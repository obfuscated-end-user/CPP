// https://www.learncpp.com/cpp-tutorial/stdstring_view-part-2

#include <iostream>
#include <string>
#include <string_view>

/* std::string_view getBoolName(bool b) {
    // local variables
    std::string t { "true" };
    std::string f { "false" };

    if (b)
        return t;   // reutrn a std::string_view viewing t

    return f;   // reutrn a std::string_view viewing f
}   // t and f are destroyed at the end of the function */

std::string_view getBoolName(bool b) {
    if (b)
        return "true";  // return a std::string_view viewing "true"
    return "false"; // return a std::string_view viewing "false"
}   // "true" and "false" are not destroyed at the end of the function

int main() {
    std::cout << getBoolName(true) << ' ' << getBoolName(false) << '\n';    // undefined behavior

    return 0;
}