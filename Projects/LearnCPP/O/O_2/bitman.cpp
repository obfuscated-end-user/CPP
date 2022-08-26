// https://www.learncpp.com/cpp-tutorial/bitwise-operators/

/*
A bitwise rotation is like a bitwise shift, except that any bits shifted off one end are added back to the other end. For example 0b1001u << 1 would be 0b0010u, but a left rotate by 1 would result in 0b0011u instead. Implement a function that does a left rotate on a std::bitset<4>. For this one, it’s okay to use test() and set().

The following code should execute:

#include <bitset>
#include <iostream>

// "rotl" stands for "rotate left"
std::bitset<4> rotl(std::bitset<4> bits)
{
// Your code here
}

int main()
{
	std::bitset<4> bits1{ 0b0001 };
	std::cout << rotl(bits1) << '\n';

	std::bitset<4> bits2{ 0b1001 };
	std::cout << rotl(bits2) << '\n';

	return 0;
}

and print the following:

0010
0011
*/

#include <bitset>
#include <iostream>

// "rotl" stands for "rotate left"
// FUCK THIS SHIT
/* std::bitset<4> rotl(std::bitset<4> bits) {
    std::bitset<4> temp = bits;
    if (temp.test(3) == 1) {
        temp <<= 1;
        temp.set(0) = 1;
    } else if (temp.test(3) == 0) {
        temp <<= 1;
        temp.set(0) = 0;
    } else {
        temp <<= 1;
    }
    return temp;
} */

// correct answer
std::bitset<4> rotl(std::bitset<4> bits) {
	const bool leftbit{ bits.test(3) };
	bits <<= 1; // do left shift
	if (leftbit)
		bits.set(0);
	return bits;
}

int main() {
	std::bitset<4> bits1{ 0b0001 };
	std::cout << rotl(bits1) << '\n';
	std::bitset<4> bits2{ 0b1001 };
	std::cout << rotl(bits2) << '\n';
	return 0;
}