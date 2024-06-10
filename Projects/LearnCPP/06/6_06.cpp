// https://www.learncpp.com/cpp-tutorial/internal-linkage

#include <iostream>

static int g_x; // non-constant globals have external linkage by default, but can be given internal linkage via the static keyword
const int g_y { 1 }; // const globals have internal linkage by default
constexpr int g_z { 2 }; // constexpr globals have internal linkage by default

int main() {
    return 0;
}