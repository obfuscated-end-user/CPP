// https://www.learncpp.com/cpp-tutorial/introduction-to-lambdas-anonymous-functions

#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

int main() {
	// Print a value and count how many times @print has been called.
	auto print {
		[](auto value) {
			static int callCount { 0 };
			std::cout << callCount++ << ": " << value << '\n';
		}
	};

	print("hello"); // 0: hello
	print("world"); // 1: hello

	print(1);	// 0: 1
	print(2);	// 1: 2

	print("ding dong"); // ding dong

	return 0;
}