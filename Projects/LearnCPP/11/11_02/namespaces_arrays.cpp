// https://www.learncpp.com/cpp-tutorial/arrays-part-ii

namespace StudentNames {
    enum StudentNames {
        kenny, // 0
        kyle, // 1
        stan, // 2
        butters, // 3
        cartman, // 4
        wendy, // 5
        max_students // 6
    };
}

int main() {
    int testScores[StudentNames::max_students]{}; // allocate 6 integers
    testScores[StudentNames::stan] = 76;

    return 0;
}