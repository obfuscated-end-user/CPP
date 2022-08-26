// https://www.learncpp.com/cpp-tutorial/unscoped-enumerations/

enum Pet {
    cat,
    dog,
    pig,
    whale,
};

enum Color {
    black,
    red,
    blue,
};

int main() {
    Pet myPet { black }; // compile error: black is not an enumerator of Pet
    Color shirt { pig }; // compile error: pig is not an enumerator of Color

    return 0;
}