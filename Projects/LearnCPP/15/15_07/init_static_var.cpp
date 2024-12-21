// https://www.learncpp.com/cpp-tutorial/static-member-functions

#include <iostream>

struct Chars {
    char first {};
    char second {};
    char third {};
    char fourth {};
    char fifth {};
};

struct MyClass1 {
    static inline Chars s_mychars { 'a', 'e', 'i', 'o', 'u' };  // initialize static variable at point of definition
};

class MyClass2 {
private:
    static Chars generate() {
        Chars c {};     // create an object
        c.first = 'a';  // fill it with values however you like
        c.second = 'e';
        c.third = 'i';
        c.fourth = 'o';
        c.fifth = 'u';

        return c;       // return the object
    }

public:
    static inline Chars s_mychars { generate() };   // copy the returned object into s_mychars
};

int main() {
    std::cout << MyClass1::s_mychars.third;  // print i
    std::cout << MyClass2::s_mychars.third;  // print i

    return 0;
}