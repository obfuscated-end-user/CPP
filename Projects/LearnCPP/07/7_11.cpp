// https://www.learncpp.com/cpp-tutorial/halts-exiting-your-program-early/

#include <iostream>
#include <cstdlib> // for std::exit()

void cleanup() {
    // code here to do any kind of cleanup required
    std::cout << "cleanup!\n";
}

int main() {
    /* int x;
    std::cout << "Enter something: ";
    std::cin >> x;
    std::exit(x); */
    // return 0;
    
    // register cleanup() to be called automatically when std::exit() is called
    /* std::atexit(cleanup); // note: we use cleanup rather than cleanup() since we're not making a function call to cleanup() right now
    std::cout << 1 << '\n';
    std::exit(0); // terminate and return status code 0 to operating system
    // The following statements never execute
    std::cout << 2 << '\n'; */
    std::abort();
}