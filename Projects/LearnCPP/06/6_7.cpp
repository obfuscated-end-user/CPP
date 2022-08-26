// https://www.learncpp.com/cpp-tutorial/external-linkage-and-variable-forward-declarations/

#include <iostream>

int g_x { 2 }; // non-constant globals are external by default
extern const int g_y { 3 }; // const globals can be defined as extern, making them external
extern constexpr int g_z { 3 }; // constexpr globals can be defined as extern, making them external (this is useless)

int main() {
    return 0;
}