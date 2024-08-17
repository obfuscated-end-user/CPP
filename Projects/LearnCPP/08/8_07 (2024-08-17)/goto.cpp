// https://www.learncpp.com/cpp-tutorial/goto-statements

// don't use goto in any of your future projects my guy

#include <iostream>
#include <cmath>

void printCats(bool skip) {
    if (skip)
        goto end;   // jump forward
    
    std::cout << "cats\n";
end:
    ;   // statement labels must be associated with a statement
}

int main() {
    double x {};

tryAgain:   // this is a statement label
    std::cout << "Enter a non-negative number: ";
    std::cin >> x;

    if (x < 0.0)
        goto tryAgain;
    
    std::cout << "The square root of " << x << " is " << std::sqrt(x) << '\n';

    printCats(true);    // jumps over print statement
    printCats(false);   // "cats"

    return 0;
}