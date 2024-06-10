// https://www.learncpp.com/cpp-tutorial/numeral-systems-decimal-binary-hexadecimal-and-octal

#include <iostream>
#include <bitset> // for std::bitset

int main() {
    int x{ 012 };           // 0 before the number means this is octal
    int y{ 0xF };           // 0x before the number means this is hexadecimal
    std::cout << x << '\n';
    std::cout << y << '\n';

    int bin{};        // assume 16-bit ints
    bin = 0b1;        // assign binary 0000 0000 0000 0001 to the variable
    bin = 0b11;       // assign binary 0000 0000 0000 0011 to the variable
    bin = 0b1010;     // assign binary 0000 0000 0000 1010 to the variable
    bin = 0b11110000; // assign binary 0000 0000 1111 0000 to the variable

    bin = { 0b1011'0010 };          // assign binary 1011 0010 to the variable
    long value { 2'132'673'462 };   // much easier to read than 2132673462

    x = { 12 };
    std::cout << x << '\n';                 // decimal (by default), 12
    std::cout << std::hex << x << '\n';     // hexadecimal, c
    std::cout << x << '\n';                 // now hexadecimal, c
    std::cout << std::oct << x << '\n';     // octal, 14
    std::cout << std::dec << x << '\n';     // return to decimal, 12
    std::cout << x << '\n';                 // decimal, 12

    // std::bitset<8> means we want to store 8 bits
	std::bitset<8> bin1{ 0b1100'0101 }; // binary literal for binary 1100 0101
	std::bitset<8> bin2{ 0xC5 };        // hexadecimal literal for binary 1100 0101

	std::cout << bin1 << ' ' << bin2 << '\n';
	std::cout << std::bitset<4>{ 0b1010 } << '\n'; // create a temporary std::bitset and print it
    return 0;
}