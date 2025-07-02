// https://www.learncpp.com/cpp-tutorial/stdvector-and-the-unsigned-length-and-subscript-problem

#include <iostream>

void foo (unsigned int) {}

int main() {
	int s1 { 5 };

	// compiles just like fine for me for some reason
	[[maybe_unused]] unsigned int u1 { s1 }; // compile error: list initialization disallows narrowing conversion
	foo(s1);								 // possible warning: copy initialization allows narrowing conversion

	constexpr int s2 { 5 };					 // now constexpr
	[[maybe_unused]] unsigned int u2 { s2 };	// ok: s is constexpr and can be converted safely, not a narrowing conversion
	foo(s2);									// ok: s is constexpr and can be converted safely, not a narrowing conversion

	return 0;
}