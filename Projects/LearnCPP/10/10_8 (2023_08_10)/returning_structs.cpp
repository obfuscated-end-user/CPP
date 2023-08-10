// https://www.learncpp.com/cpp-tutorial/passing-and-returning-structs

#include <iostream>

struct Point3d {
    double x = 0;
    double y = 0;
    double z = 0;
};

Point3d getZeroPoint() {
    // We can create a variable and return the variable (we'll improve this below)
//  Point3d temp { 0.0, 0.0, 0.0 };
//  return temp;
//  return Point3d { 0.0, 0.0, 0.0 }; // return an unnamed Point3d
    return { 0.0, 0.0, 0.0 };   // you can also do this
//  return {};  // or even this
}

int main() {
    Point3d zero { getZeroPoint() };

    if (zero.x == 0.0 && zero.y == 0.0 && zero.z == 0.0)
        std::cout << "The point is zero\n";
    else
        std::cout << "The point is not zero\n";

    return 0;
}