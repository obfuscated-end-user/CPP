// https://www.learncpp.com/cpp-tutorial/lambda-captures/

#include <iostream>

int main() {
    int ammo = 10;

    // Define a lambda and store it in a variable called "shoot".
    auto shoot = [ammo]() {
            // Illegal, ammo was captured as a const copy.
            --ammo;
            std::cout << "Pew! " << ammo << " shot(s) left.\n";
        };

    // Call the lambda
    shoot();

    std::cout << ammo << " shot(s) left\n";

    return 0;
}