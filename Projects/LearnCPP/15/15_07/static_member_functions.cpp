// https://www.learncpp.com/cpp-tutorial/static-member-functions

#include <iostream>

class Something {
private:
    static inline int s_value { 1 };

public:
    static int getValue() { // static member function
        return s_value;
    }
};

int main() {
    // std::cout << Something::s_value;    // error: s_value is private and can't be accessed directly outside the class
    std::cout << Something::getValue() << '\n';

    return 0;
}