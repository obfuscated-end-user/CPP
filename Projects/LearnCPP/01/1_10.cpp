// https://www.learncpp.com/cpp-tutorial/introduction-to-expressions

#include <iostream>

int five() {
    int nsiovndpvindfpvioadfnviosdmfvaios0924g094gh34jqwrvioadf_____AAAAAAA = 1;
    return nsiovndpvindfpvioadfnviosdmfvaios0924g094gh34jqwrvioadf_____AAAAAAA;
}
int main() {
    int a{ 2 };             // initialize variable a with literal value 2
    int b{ 2 + 3 };         // initialize variable b with computed value 5
    int c{ (2 * 3) + 4 };   // initialize variable c with computed value 10
    int d{ b };             // initialize variable d with variable value 5
    int e{ five() };        // initialize variable e with function return value 5

    std::cout << e;
    return 0;
}