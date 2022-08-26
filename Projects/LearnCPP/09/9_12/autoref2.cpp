// https://www.learncpp.com/cpp-tutorial/type-deduction-with-pointers-references-and-const/

#include <string>

std::string& getRef(); // some function that returns a reference to const

int main() {
    auto ref1 { getRef() };  // std::string (reference dropped)
    auto& ref2 { getRef() }; // std::string& (reference reapplied)

    return 0;
}