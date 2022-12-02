// https://www.learncpp.com/cpp-tutorial/static-member-variables/

#include <iostream>

class Something {
public:
    static int s_value;
};

int Something::s_value{ 1 };

int main() {
    Something first;
    Something second;

    first.s_value = 2;

    std::cout << first.s_value << '\n';
    std::cout << second.s_value << '\n';
    return 0;
}

// Because s_value is a static member variable, s_value is shared between all objects of the class. Consequently, first.s_value is the same variable as second.s_value.