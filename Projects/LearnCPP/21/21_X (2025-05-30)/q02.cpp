// https://www.learncpp.com/cpp-tutorial/chapter-21-summary-and-quiz

/*
Write a class named Average that will keep track of the average of all integers passed to it. Use two members: The first one should be type std::int32_t, and used to keep track of the sum of all the numbers you’ve seen so far. The second should keep track of how many numbers you’ve seen so far. You can divide them to find your average.

a) Write all of the functions necessary for the following program to run:

```
int main()
{
	Average avg{};
	std::cout << avg << '\n';

	avg += 4;
	std::cout << avg << '\n'; // 4 / 1 = 4

	avg += 8;
	std::cout << avg << '\n'; // (4 + 8) / 2 = 6

	avg += 24;
	std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

	avg += -10;
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

	(avg += 6) += 10; // 2 calls chained together
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

	Average copy{ avg };
	std::cout << copy << '\n';

	return 0;
}
```

and produce the result:

```
0
4
6
12
6.5
7
7
```
*/

#include <iostream>
#include <cstdint>  // for fixed width integers

class Average {
private:
    std::int32_t m_total { 0 }; // the sum of all numbers we've seen so far
    int m_numbers { 0 };        // the count of numbers we've seen so far

public:
    Average() {}

    friend std::ostream& operator<<(std::ostream& out, const Average& average) {
        // Handle case where we haven't seen any numbers yet
        if (average.m_numbers == 0) {
            out << 0;
            return out;
        }

        // Our average is the sum of the numbers we've seen divided by the count of the numbers we've seen
        // We need to remember to do a floating point division here, not an integer division
        out << static_cast<double>(average.m_total) / average.m_numbers;

        return out;
    }

    // Because operator+= modifies its left operand, we'll write it as a member
    Average& operator+=(std::int32_t num) {
        // Increment our total by the new number
        m_total += num;
        // And increase the count by 1
        ++m_numbers;

        // return *this in case someone wants to chain +='s together
        return *this;
    }
};

int main() {
    Average avg {};
    std::cout << avg << '\n';

    avg += 4;
    std::cout << avg << '\n';

    avg += 8;
    std::cout << avg << '\n';

    avg += 24;
    std::cout << avg << '\n';

    avg += -10;
    std::cout << avg << '\n';

    (avg += 6) += 10;   // 2 calls chained together
    std::cout << avg << '\n';

    Average copy { avg };
    std::cout << copy << '\n';

    return 0;
}