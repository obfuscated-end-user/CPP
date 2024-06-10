// https://www.learncpp.com/cpp-tutorial/function-template-instantiation

#include "max.h" // import template definition for max<T, T>()
#include <iostream>

void foo() {
	std::cout << max(3, 2);
}