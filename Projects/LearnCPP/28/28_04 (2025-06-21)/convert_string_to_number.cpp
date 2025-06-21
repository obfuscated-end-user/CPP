// https://www.learncpp.com/cpp-tutorial/stream-classes-for-strings

#include <iostream>
#include <sstream>

int main() {
    std::stringstream os {};
    os << "12345 67.89";    // insert a string of numbers into the stream
    int nValue {};
    double dValue {};

    os >> nValue >> dValue;

    std::cout << nValue << ' ' << dValue << '\n';

    return 0;
}