// https://www.learncpp.com/cpp-tutorial/arrays-part-ii

#include <iostream>

void passValue(int value) { // value is a copy of the argument
    value = 99; // so changing it here won't change the value of the argument
}

void passArray(int prime[5]) { // prime is the actual array
    prime[0] = 11; // so changing it here will change the original argument!
    prime[1] = 7;
    prime[2] = 5;
    prime[3] = 3;
    prime[4] = 2;
    // make the parameter "const int prime[5]" in order to not modify the original array
}

int main() {
    int value{ 1 };
    std::cout << "before passValue: " << value << '\n';
    passValue(value);
    std::cout << "after passValue: " << value << '\n';

    int prime[5]{ 2, 3, 5, 7, 11 };
    std::cout << "before passArray: " << prime[0] << " " << prime[1] << " " << prime[2] << " " << prime[3] << " " << prime[4] << '\n';
    passArray(prime);
    std::cout << "after passArray: " << prime[0] << " " << prime[1] << " " << prime[2] << " " << prime[3] << " " << prime[4] << '\n';

    return 0;
}