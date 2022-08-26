// https://www.learncpp.com/cpp-tutorial/struct-passing-and-miscellany/

#include <iostream>

struct Point3d {
    double x { 0.0 };
    double y { 0.0 };
    double z { 0.0 };
};

Point3d getZeroPoint() {
    // We can create a variable and return the variable (we'll improve this below)
    Point3d temp { 0.0, 0.0, 0.0 };
    return temp;
}

/*
// We can make our function slightly better by returning a temporary (unnamed) object instead:
Point3d getZeroPoint() {
    return Point3d { 0.0, 0.0, 0.0 }; // return an unnamed Point3d
}

// In the case where the function has an explicit return type (e.g. Point3d) instead of using type deduction (an auto return type), we can even omit the type in the return statement:
Point3d getZeroPoint() {
    // We already specified the type at the function declaration
    // so we don't need to do so here again
    return { 0.0, 0.0, 0.0 }; // return an unnamed Point3d
}

// Also note that since in this case we’re returning all zero values, we can use empty braces to return a value-initialized Point3d:
Point3d getZeroPoint() {
    // We can use empty curly braces to value-initialize all members
    return {};
}
*/

int main() {
    Point3d zero{ getZeroPoint() };

    if (zero.x == 0.0 && zero.y == 0.0 && zero.z == 0.0)
        std::cout << "The point is zero\n";
    else
        std::cout << "The point is not zero\n";

    return 0;
}