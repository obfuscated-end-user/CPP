// https://www.learncpp.com/cpp-tutorial/void-pointers/

#include <iostream>

struct Something {
    int n;
    float f;
};

int main() {
    int nValue;
    float fValue;

    Something sValue;

    void* ptr;
    ptr = &nValue; // valid
    ptr = &fValue; // valid
    ptr = &sValue; // valid
    return 0;
}