// https://www.learncpp.com/cpp-tutorial/introduction-to-type-conversion-and-static_cast/

#include <iostream>

void print(int x) { // print takes an double parameter 
	std::cout << x;
}

int main() {
	// print(5); // what happens when we pass an int value?
    // print(static_cast<int>(5.5));

    unsigned int u { 513u }; // 5u means the number 5 as an unsigned int
    int s { static_cast<int>(u) }; // return value of variable u as an int
    std::cout << s;

    std::int8_t myint{65}; // initialize myint with value 65
    std::cout << myint; // A

	return 0;
}