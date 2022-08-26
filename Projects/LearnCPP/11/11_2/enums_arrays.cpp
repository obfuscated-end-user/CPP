// https://www.learncpp.com/cpp-tutorial/arrays-part-ii/

enum StudentNames {
    kenny, // 0
    kyle, // 1
    stan, // 2
    butters, // 3
    cartman, // 4
    max_students // 5
};

int main() {
    int testScores[max_students]{}; // allocate 5 integers
    testScores[stan] = 76;

    return 0;
}