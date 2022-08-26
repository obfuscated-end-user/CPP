// https://www.learncpp.com/cpp-tutorial/basic-debugging-tactics/

#include <iostream>

/* int getValue() {
	return 4;
}

int main() {
    std::cout << getValue;
    return 0;
} */


int getValue() {
std::cerr << "getValue() called\n";
	return 4;
}

int main() {
std::cerr << "main() called\n";
    std::cout << getValue;
    return 0;
}