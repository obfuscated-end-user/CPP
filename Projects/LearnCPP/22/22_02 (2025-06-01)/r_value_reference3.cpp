// https://www.learncpp.com/cpp-tutorial/rvalue-references

#include <iostream>

int main() {
	int&& rref { 5 };	// because we're initializing an r-vlaue reference with a literal, a temporary with value 5 is created here
	rref = 10;
	std::cout << rref << '\n';

	return 0;
}