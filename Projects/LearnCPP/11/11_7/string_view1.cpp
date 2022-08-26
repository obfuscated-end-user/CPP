// https://www.learncpp.com/cpp-tutorial/stdstring_view-part-2/

#include <iostream>
#include <string_view>

int main() {
  std::string_view text{ "hello" }; // view the text "hello", which is stored in the binary
  std::string_view str{ text }; // view of the same "hello"
  std::string_view more{ str }; // view of the same "hello"

    std::cout << text << ' ' << str << ' ' << more << '\n';

    return 0;
}