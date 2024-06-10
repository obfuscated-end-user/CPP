// https://www.learncpp.com/cpp-tutorial/pass-by-address-part-2

#include <iostream>
#include <string>

void greet() {
    std::cout << "Hello guest\n";
}

void greet(const std::string& name) { // name now passed by const reference
    std::cout << "Hello " << name << '\n';
}

int main() {
    greet(); // we don't know who the user is yet
    std::string joe{ "Joe" };
    greet(joe); // we know the user is joe

    return 0;
}