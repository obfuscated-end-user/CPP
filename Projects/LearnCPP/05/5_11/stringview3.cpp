// https://www.learncpp.com/cpp-tutorial/stdstring_view-part-2

#include <iostream>
#include <string>
#include <string_view>

int main() {
    std::string_view sv {};

    {   // create a nested block
        std::string s { "Hello, world!" };  // create a std::string local to this nested block
        // std::string s { "pa_╘j☺P☺_╘j☺ggsr" };  // create a std::string local to this nested block
        sv = s;                             // sv is now viewing s
    }   // s is destroyed here, so sv is now viewing an invalid string

    std::cout << sv << '\n';    // undefined behavior

    return 0;
}