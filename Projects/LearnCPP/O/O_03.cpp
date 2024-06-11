// https://www.learncpp.com/cpp-tutorial/bit-manipulation-with-bitwise-operators-and-bit-masks

#include <iostream>
#include <cstdint>
#include <bitset>

int main() {
    // A bit mask is a predefined set of bits that is used to select which
    // specific bits will be modified by subsequent operations.

    /*
    // bit masks in C++ 11 or earlier
    constexpr std::uint8_t mask0{ 0x01 }; // hex for 0000 0001
    constexpr std::uint8_t mask1{ 0x02 }; // hex for 0000 0010
    constexpr std::uint8_t mask2{ 0x04 }; // hex for 0000 0100
    constexpr std::uint8_t mask3{ 0x08 }; // hex for 0000 1000
    constexpr std::uint8_t mask4{ 0x10 }; // hex for 0001 0000
    constexpr std::uint8_t mask5{ 0x20 }; // hex for 0010 0000
    constexpr std::uint8_t mask6{ 0x40 }; // hex for 0100 0000
    constexpr std::uint8_t mask7{ 0x80 }; // hex for 1000 0000
    */

    // bit masks in C++ 14, use this
    constexpr std::uint8_t mask0{ 0b0000'0001 }; // represents bit 0
    constexpr std::uint8_t mask1{ 0b0000'0010 }; // represents bit 1
    constexpr std::uint8_t mask2{ 0b0000'0100 }; // represents bit 2
    constexpr std::uint8_t mask3{ 0b0000'1000 }; // represents bit 3
    constexpr std::uint8_t mask4{ 0b0001'0000 }; // represents bit 4
    constexpr std::uint8_t mask5{ 0b0010'0000 }; // represents bit 5
    constexpr std::uint8_t mask6{ 0b0100'0000 }; // represents bit 6
    constexpr std::uint8_t mask7{ 0b1000'0000 }; // represents bit 7

    // testing a bit to see if it is on or off
    // To determine if a bit is on or off, we use bitwise AND in conjunction
    // with the bit mask for the appropriate bit:
    std::uint8_t flags{ 0b0000'0101 }; // 8 bits in size means room for 8 flags
	std::cout << "bit 0 is " << ((flags & mask0) ? "on\n" : "off\n");
	std::cout << "bit 1 is " << ((flags & mask1) ? "on\n\n" : "off\n\n");

    // setting a bit
    // To set (turn on) a bit, we use bitwise OR equals (operator |=)
    // in conjunction with the bit mask for the appropriate bit:
    std::cout << "bit 1 is " << ((flags & mask1) ? "on\n" : "off\n");
    flags |= mask1; // turn on bit 1
    std::cout << "bit 1 is " << ((flags & mask1) ? "on\n\n" : "off\n\n");
    // We can also turn on multiple bits at the same time using Bitwise OR:
    flags |= (mask4 | mask5); // turn bits 4 and 5 on at the same time

    // resetting a bit
    // To clear a bit (turn off), we use Bitwise AND and Bitwise NOT together:
    std::cout << "bit 2 is " << ((flags & mask2) ? "on\n" : "off\n");
    flags &= ~mask2; // turn off bit 2
    std::cout << "bit 2 is " << ((flags & mask2) ? "on\n\n" : "off\n\n");

    // flipping a bit
    // To toggle a bit state, we use Bitwise XOR:
    std::cout << "bit 2 is " << ((flags & mask2) ? "on\n" : "off\n");
    flags ^= mask2; // flip bit 2
    std::cout << "bit 2 is " << ((flags & mask2) ? "on\n" : "off\n");
    flags ^= mask2; // flip bit 2
    std::cout << "bit 2 is " << ((flags & mask2) ? "on\n\n" : "off\n\n");

    /*
    in short:
    & -             check if bit is on or off
    | or |= -       set to 1 (turn on) a bit
    & ~ or &= ~ -   reset to 0 (turn off) a bit
    ^ or ^= -       flip bits
    */

    // practical use for this:
    /* // Define a bunch of physical/emotional states
	constexpr std::uint8_t isHungry{	1 << 0 }; // 0000 0001
	constexpr std::uint8_t isSad{		1 << 1 }; // 0000 0010
	constexpr std::uint8_t isMad{		1 << 2 }; // 0000 0100
	constexpr std::uint8_t isHappy{		1 << 3 }; // 0000 1000
	constexpr std::uint8_t isLaughing{ 	1 << 4 }; // 0001 0000
	constexpr std::uint8_t isAsleep{	1 << 5 }; // 0010 0000
	constexpr std::uint8_t isDead{		1 << 6 }; // 0100 0000
	constexpr std::uint8_t isCrying{	1 << 7 }; // 1000 0000

	std::uint8_t me{}; // all flags/options turned off to start
	me |= (isHappy | isLaughing); // I am happy and laughing
	me &= ~isLaughing; // I am no longer laughing

	// Query a few states
	// (we'll use static_cast<bool> to interpret the results as a boolean value)
	std::cout << "I am happy? " << static_cast<bool>(me & isHappy) << '\n';
	std::cout << "I am laughing? " << static_cast<bool>(me & isLaughing) << '\n'; */

    // same thing but uses std::bitset
    // Define a bunch of physical/emotional states
	constexpr std::bitset<8> isHungry{	0b0000'0001 };
	constexpr std::bitset<8> isSad{		0b0000'0010 };
	constexpr std::bitset<8> isMad{		0b0000'0100 };
	constexpr std::bitset<8> isHappy{	0b0000'1000 };
	constexpr std::bitset<8> isLaughing{	0b0001'0000 };
	constexpr std::bitset<8> isAsleep{	0b0010'0000 };
	constexpr std::bitset<8> isDead{	0b0100'0000 };
	constexpr std::bitset<8> isCrying{	0b1000'0000 };

	std::bitset<8> me{}; // all flags/options turned off to start
	me |= (isHappy | isLaughing); // I am happy and laughing
	me &= ~isLaughing; // I am no longer laughing

	// Query a few states (we use the any() function to see if any bits remain set)
	std::cout << "I am happy? " << (me & isHappy).any() << '\n';
	std::cout << "I am laughing? " << (me & isLaughing).any() << '\n';
    return 0;
}