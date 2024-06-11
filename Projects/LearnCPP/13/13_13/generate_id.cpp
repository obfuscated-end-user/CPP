// https://www.learncpp.com/cpp-tutorial/static-member-variables

#include <iostream>

int generateID() {
    static int s_id{ 0 };
    return ++s_id;
}

int main() {
    std::cout << generateID() << '\n';
    std::cout << generateID() << '\n';
    std::cout << generateID() << '\n';

    return 0;
}