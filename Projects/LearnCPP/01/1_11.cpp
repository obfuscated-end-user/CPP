// https://www.learncpp.com/cpp-tutorial/developing-your-first-program

#include <iostream>

int main()
{
    int number;
    std::cout << "Enter an integer: ";
    std::cin >> number;
    std::cout << "Double that number is: ";
    number *= 2;
    std::cout << number;
}
/*
preferred version
    std::cout << "Enter an integer: ";
	int num{ };
	std::cin >> num;
	std::cout << "Double that number is: " <<  num * 2 << '\n'; // use an expression to multiply num * 2 at the point where we are going to print it
*/