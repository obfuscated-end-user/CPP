// https://www.learncpp.com/cpp-tutorial/stdstring_view-part-2/

#include <iostream>
#include <string>

int main() {
    char text[]{ "hello" };
    std::string str{ text };
    std::string more{ str };

    std::cout << text << ' ' << str << ' ' << more << '\n';

    return 0;
}