// // https://www.learncpp.com/cpp-tutorial/in-and-out-parameters

#include <iostream>

int getByValue() {
    return 5;
}

void getByReference(int& x) {
    x = 5;
}

int main() {
    // return by value
    [[maybe_unused]] int x = getByValue();  // can use to initialize object
    std::cout << getByValue() << '\n';      // can use temporary return value in expression

    // return by out parameter
    int y;                  // must first allocate an assignable object
    getByReference(y);      // then pass to function to assign the desired value
    std::cout << y << '\n'; // and only then can we use that value

    return 0;
}