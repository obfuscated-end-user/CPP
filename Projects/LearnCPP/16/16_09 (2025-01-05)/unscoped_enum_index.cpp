// https://www.learncpp.com/cpp-tutorial/array-indexing-and-length-using-enumerators

#include <vector>

namespace Students {
    enum Names {
        kenny,          // 0
        kyle,           // 1
        stan,           // 2
        butters,        // 3
        cartman,        // 4
        max_students    // 5
    };
}

int main() {
    std::vector testScores { 78, 94, 66, 77, 14 };

    testScores[Students::stan] = 76;    // we are now updating the test score belonging to stan

    Students::Names name { Students::stan };    // non-constexpr
    testScores[name] = 76;  // may trigger a sign conversion warning if Student::Names defaults to a signed underlying type

    return 0;
}