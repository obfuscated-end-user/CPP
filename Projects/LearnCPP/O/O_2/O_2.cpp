// https://www.learncpp.com/cpp-tutorial/bitwise-operators/

#include <bitset>
#include <iostream>

int main() {
    std::bitset<4> x { 0b1100 };
    std::cout << x << '\n';
    std::cout << (x >> 1) << '\n'; // shift right by 1, yielding 0110
    std::cout << (x << 1) << "\n\n"; // shift left by 1, yielding 1000

    // "<< and >> are used for inputs and outputs you absolute fucking retard, what's with this binary shit?"
    unsigned int y { 0b0100 };
    y = y << 1;                                     // use operator<< for left shift
    std::cout << std::bitset<4>{ y } << "\n\n";     // use operator<< for output

    // parentheses are important
    std::bitset<4> z{ 0b0110 };
	std::cout << z << 1 << '\n'; // print value of z (0110), then 1
	std::cout << (z << 1) << "\n\n"; // print z left shifted by 1 (1100)

    // ~ is a bitwise NOT operator
    // for the second one, since it has size 8, it gets evaluated to 0000'0100. then the not operator
    // flips the bits, which results into 1111'1011. (apostrophe added for readability)
    std::cout << ~std::bitset<4>{ 0b0100 } << ' ' << ~std::bitset<8>{ 0b0100 } << "\n\n";

    // | is a bitwise OR operator
    // you know, do the logical or thing by value by columns
    // for example, the first bit on the first number is 1, and the first bit on the secondnumber is 0
    // true | false evaluates to true, so the answer is 1 on the first position. (explain this shit better)
    // 1st: 0101
    // 2nd: 0110
    // ans: 0111
    std::cout << (std::bitset<4>{ 0b0101 } | std::bitset<4>{ 0b0110 }) << '\n';
    // it can also be more than 2 values:
    std::cout << (std::bitset<4>{ 0b0111 } | std::bitset<4>{ 0b0011 } | std::bitset<4>{ 0b0001 }) << "\n\n";

    // & is a bitwise AND operator
    // works like the OR one, but with AND.
    std::cout << (std::bitset<4>{ 0b0101 } & std::bitset<4>{ 0b0110 }) << '\n';
    // compound AND expression
    std::cout << (std::bitset<4>{ 0b0001 } & std::bitset<4>{ 0b0011 } & std::bitset<4>{ 0b0111 }) << "\n\n";

    // ^ is a bitwise XOR operator
    // XOR evaluates to true if one and only one of its operands is true.
    // if neither or both are true, it evaluates to 0.
    std::cout << (std::bitset<4>{ 0b0101 } ^ std::bitset<4>{ 0b0110 }) << "\n\n";

    // magic
    std::bitset<4> bits { 0b0100 };
    bits >>= 1;                     // what the fuck
    std::cout << bits;
    return 0;
}