// https://www.learncpp.com/cpp-tutorial/static-member-variables

#include <iostream>

class Something {
public:
    static int s_value; // declares the static member variable
};

int Something::s_value{ 1 }; // defines the static member variable (we'll discuss this section below)

int main() {
    // note: we're not instantiating any objects of type Something
    Something::s_value = 2;
    std::cout << Something::s_value << '\n';
    return 0;
}

// Access static members by class name (using the scope resolution operator) rather than through an object of the class (using the member selection operator).

// in case you forgot, that double colon thing after a class name preceded by an attribute related to that class is the same on how you do with namespaces. we're not instantiating anything, we're literally setting it directly from the class rather than creating an object to modify something