// https://www.learncpp.com/cpp-tutorial/static-member-functions

#include <iostream>

class Something {
private:
    static int s_value;
public:
    // static member function
    // can access the private static int variable from above
    static int getValue() {
        return s_value;
    }
};

int Something::s_value{ 1 }; // initializer

int main() {
    std::cout << Something::getValue() << '\n';
}

/*
notes:
static functions have no *this pointer
static functions can't access non-static members
*/