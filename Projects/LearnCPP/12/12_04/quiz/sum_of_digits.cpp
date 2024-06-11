// https://www.learncpp.com/cpp-tutorial/recursion

/*
2. Write a recursive function that takes an integer as input and returns the sum of each individual digit in the integer (e.g. 357 = 3 + 5 + 7 = 15). Print the answer for input 93427 (which is 25). Assume the input values are positive.
*/

#include <iostream>

int sumOfDigits(int num) {
    static int count = 1;
    if (num < 10)   // if num is 1 digit long
		return num; // return itself
    std::cout << "ran " << count << " times\n";
    std::cout << num << '\n';
    ++count;
    // else, do integer division on num by 10, since that will give the same number except with the last digit omitted from the right. after that, add it with num % 10, since that is the last digit from the right that was omitted from earlier.
	return sumOfDigits(num / 10) + num % 10;    
}

/*
num = 93427
sumOfDigits(93427 / 10) + 93427 % 10    = sumOfDigits(9342) + 7
sumOfDigits(9342 / 10) + 9342 % 10      = sumOfDigits(934) + 2
sumOfDigits(934 / 10) + 934 % 10        = sumOfDigits(93) + 4
sumOfDigits(93 / 10) + 93 % 10          = sumOfDigits(9) + 3
sumOfDigits(9 / 10) + 9 % 10            = sumOfDigits(0) + 9
sumOfDigits(0 / 10) + 0 % 10            = sumOfDigits(0) + 0    not sure if this bit actually runs
*/

int main() {
    
    /* int num1 = 15;
    int num2 = num1 / 10;   // 1
    int num3 = num1 % 10;   // 5
    int num4 = num2 + num3;

    std::cout << num1 << '\n';
    std::cout << num2 << '\n';
    std::cout << num3 << '\n';
    std::cout << num4 << '\n'; */
    
    std::cout << sumOfDigits(93427) << '\n';
    return 0;
}