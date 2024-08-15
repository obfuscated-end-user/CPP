// https://www.learncpp.com/cpp-tutorial/introduction-to-type-conversion-and-static_cast

#include <iostream>
#include <cstdint>

void print(int x) { // print takes an double parameter 
	std::cout << x;
}

int main() {
	// print(5); // what happens when we pass an int value?
    // print(static_cast<int>(5.5));

    unsigned int u { 513u }; // 5u means the number 5 as an unsigned int
    int s { static_cast<int>(u) }; // return value of variable u as an int
    std::cout << s << '\n';

    std::int8_t myInt { 65 }; // initialize myint with value 65
    std::cout << myInt << '\n'; // prints "A", std::int8_t is treated as a char (for now)
    std::cout << static_cast<int>(myInt) << '\n'; // 65 now here after using static_cast<T>()

    std::cout << "Enter a number between 0 and 127: ";
    std::int8_t myInt2 {};
    std::cin >> myInt2;
    std::cout << "You entered: " << static_cast<int>(myInt2) << '\n';

	return 0;
}