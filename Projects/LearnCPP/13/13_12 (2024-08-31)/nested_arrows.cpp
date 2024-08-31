// https://www.learncpp.com/cpp-tutorial/member-selection-with-pointers-and-references

#include <iostream>

struct Point {
    double x;
    double y;
};

struct Triangle {
    Point* a {};
    Point* b {};
    Point* c {};
};

int main() {
    Point a { 1, 2 };
    Point b { 3, 7 };
    Point c { 10, 2 };

    Triangle tr { &a, &b, &c };
    Triangle* ptr { &tr };

    // ptr is a pointer to a Triangle, which contains members that are pointers to a Point
    // To access member y of Point c of the Triangle pointed to by ptr, the following are equivalent:

    // access via operator.
    std::cout << (*(*ptr).c).y << '\n'; // ugly!
    
    // access via operator->
    std::cout << ptr -> c -> y << '\n';

    return 0;
}