// https://www.learncpp.com/cpp-tutorial/pass-by-address-part-2/

#include <iostream>
#include <string>

void greet(std::string* name=nullptr) { // takes a string pointer argument, with default value set to nullptr
    std::cout << "Hello ";
    std::cout << (name ? *name : "guest") << '\n';  // if it has a name, print name, else if it's a nullptr, print "guest"
}

int main() {
    greet(); // we don't know who the user is yet
    std::string joe{ "Joe" };
    greet(&joe); // we know the user is joe

    return 0;
}