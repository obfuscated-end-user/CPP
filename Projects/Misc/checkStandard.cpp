// https://stackoverflow.com/questions/46980383/how-to-determine-what-c-standard-is-the-default-for-a-c-compiler

#include <iostream>

int main() {
    std::cout << __cplusplus << std::endl;

    return 0;    
}