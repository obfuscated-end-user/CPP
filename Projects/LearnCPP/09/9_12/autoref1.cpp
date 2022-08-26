// https://www.learncpp.com/cpp-tutorial/type-deduction-with-pointers-references-and-const/

#include <string>

std::string& getRef(); // some function that returns a reference

int main() {
    auto ref { getRef() }; // type deduced as std::string (not std::string&)

    return 0;
}