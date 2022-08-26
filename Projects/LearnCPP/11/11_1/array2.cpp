// https://www.learncpp.com/cpp-tutorial/arrays-part-i/

int main() {
    int array[5]{}; // declare an array of length 5

    // using a literal (constant) index:
    array[1] = 7; // ok

    // using an enum (constant) index
    enum Animals
    {
        animal_cat = 2
    };
    array[animal_cat] = 4; // ok

    // using a variable (non-constant) index:
    int index{ 3 };
    array[index] = 7; // ok

    // using an expression that evaluates to an integer index:
    array[1+2] = 7; // ok

    return 0;
}