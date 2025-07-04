// https://www.learncpp.com/cpp-tutorial/overloading-operators-using-normal-functions

#include "Cents.h"
#include <iostream>

int main() {
	Cents cents1 { 6 };
	Cents cents2 { 8 };
	Cents centsSum { cents1 + cents2 }; // without the prototype in Cents.h, this would fail to compile
	std::cout << "I have " << centsSum.getCents() << " cents.\n";

	return 0;
}

// cd "path/containing/this/file" ; if ($?) { g++ -std=c++20 "main.cpp" "Cents.cpp" -o "main" } ; if ($?) { & ".\main" }