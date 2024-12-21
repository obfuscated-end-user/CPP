// https://www.learncpp.com/cpp-tutorial/static-member-variables

#include <iostream>

class Something {
public:
    static int s_value; // declare s_value as static
};

int Something::s_value { 1 };   // define and initialize s_value to 1

int main() {
    // note: we're not instantiating any objects of type Something

    Something::s_value = 2;
    std::cout << Something::s_value << '\n';

    return 0;
}