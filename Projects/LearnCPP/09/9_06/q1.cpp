// https://www.learncpp.com/cpp-tutorial/introduction-to-pointers

/*
What values does this program print? Assume a short is 2 bytes, and a 32-bit machine.

#include <iostream>

int main()
{
	short value{ 7 }; // &value = 0012FF60
	short otherValue{ 3 }; // &otherValue = 0012FF54

	short* ptr{ &value };

	std::cout << &value << '\n';
	std::cout << value << '\n';
	std::cout << ptr << '\n';
	std::cout << *ptr << '\n';
	std::cout << '\n';

	*ptr = 9;

	std::cout << &value << '\n';
	std::cout << value << '\n';
	std::cout << ptr << '\n';
	std::cout << *ptr << '\n';
	std::cout << '\n';

	ptr = &otherValue;

	std::cout << &otherValue << '\n';
	std::cout << otherValue << '\n';
	std::cout << ptr << '\n';
	std::cout << *ptr << '\n';
	std::cout << '\n';

	std::cout << sizeof(ptr) << '\n';
	std::cout << sizeof(*ptr) << '\n';

	return 0;
}
*/

#include <iostream>

int main() {
	short value{ 7 }; // &value = 0012FF60
	short otherValue{ 3 }; // &otherValue = 0012FF54

	short* ptr{ &value };

	std::cout << &value << '\n';        // memory address
	std::cout << value << '\n';         // 7
	std::cout << ptr << '\n';           // pointer to value
	std::cout << *ptr << '\n';          // 7
	std::cout << '\n';

	*ptr = 9;

	std::cout << &value << '\n';        // memory address
	std::cout << value << '\n';         // 9
	std::cout << ptr << '\n';           // pointer to value
	std::cout << *ptr << '\n';          // 9
	std::cout << '\n';

	ptr = &otherValue;

	std::cout << &otherValue << '\n';   // memory address
	std::cout << otherValue << '\n';    // 3
	std::cout << ptr << '\n';           // pointer to otherValue
	std::cout << *ptr << '\n';          // 3
	std::cout << '\n';

	std::cout << sizeof(ptr) << '\n';
	std::cout << sizeof(*ptr) << '\n';

	return 0;
}