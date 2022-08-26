// https://www.learncpp.com/cpp-tutorial/stdstring_view-part-2/

#include <cstring>
#include <iostream>
#include <string_view>

int main() {
    std::string_view str{ "balloon" };

    // Remove the "b"
    str.remove_prefix(1);
    // remove the "oon"
    str.remove_suffix(3);
    // Remember that the above doesn't modify the string, it only changes
    // the region that str is observing.

    std::cout << str << " has " << std::strlen(str.data()) << " letter(s)\n";
    std::cout << "str.data() is " << str.data() << '\n';
    std::cout << "str is " << str << '\n';

    return 0;
}