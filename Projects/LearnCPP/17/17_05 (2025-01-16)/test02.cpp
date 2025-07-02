// https://www.learncpp.com/cpp-tutorial/arrays-of-references-via-stdreference_wrapper

#include <array>
#include <iostream>

int main() {
	int x { 1 };
	int y { 2 };

	[[maybe_unused]] std::array<int&, 2> refarr { x, y };	// compile error: cannot define array of references

	int& ref1 { x };
	int& ref2 { y };
	[[maybe_unused]] std::array valarr { ref1, ref2 };		// ok: this is actually a std::array<int, 2>, not an array of references

	return 0;
}