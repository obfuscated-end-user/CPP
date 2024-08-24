// https://www.learncpp.com/cpp-tutorial/introduction-to-overloading-the-i-o-operators

#include <iostream>
#include <string_view>

enum Color {
    black,
    red,
    blue,
};

constexpr std::string_view getColorName(Color color) {
    switch (color) {
        case black:     return "black";
        case red:       return "red";
        case blue:      return "blue";
        default:        return "???";
    }
}

// Teach operator<< how to print a Color
// std::ostream is the type of std::cout, std::cerr, etc...
// The return type and parameter type are references (to prevent copies being made)
std::ostream& operator<<(std::ostream& out, Color color) {
    out << getColorName(color); // print ot color's name to whatever output stream out
    return out;                 // operator<< conventionally returns its left operand

    // The aboe can be condensed to the following single line:
    // return out << getColorName(color)
}

int main() {
    Color shirt { blue };
    std::cout << "Your shirt is " << shirt << '\n';
    
    return 0;
}