// https://www.learncpp.com/cpp-tutorial/unscoped-enumeration-input-and-output

#include <iostream>
#include <string>

enum Color {
    black,
    red,
    blue,
};


std::string getColor(Color color) {
    switch (color) {
    case black: return "black";
    case red:   return "red";
    case blue:  return "blue";
    default:    return "???";
    }
}

int main() {
    Color shirt { blue };
    std::cout << "Your shirt is " << getColor(shirt) << '\n';

    return 0;
}