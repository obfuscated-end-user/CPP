// https://www.learncpp.com/cpp-tutorial/lambda-captures/

#include <iostream>

int main() {
    int ammo = 10;

    auto shoot =
        // Added mutable after the parameter list.
        [ammo]() mutable {
            --ammo;
            std::cout << "Pew! " << ammo << " shot(s) left.\n";
        };
    
    shoot();
    shoot();

    std::cout << ammo << " shot(s) left\n";
}