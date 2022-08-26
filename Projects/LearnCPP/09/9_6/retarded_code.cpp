// https://www.learncpp.com/cpp-tutorial/introduction-to-pointers/

int main() {
    int i{ 5 };
    double d{ 7.0 };

    int* iPtr{ &i };     // ok: a pointer to an int can point to an int object
    int* iPtr2 { &d };   // not okay: a pointer to an int can't point to a double
    double* dPtr{ &d };  // ok: a pointer to a double can point to a double object
    double* dPtr2{ &i }; // not okay: a pointer to a double can't point to an int

    int* ptr{ 5 }; // not okay
    int* ptr{ 0x0012FF7C }; // not okay, 0x0012FF7C is treated as an integer literal
}