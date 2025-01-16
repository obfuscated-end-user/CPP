// https://www.learncpp.com/cpp-tutorial/stdarray-of-class-types-and-brace-elision

#include <array>
#include <iostream>
#include <string_view>

// Each student has an id and a name
struct Student {
    int id {};
    std::string_view name {};
};

// Our array of 3 students (single braced since we mention Student with each initializer)
constexpr std::array students { Student { 0, "Albert" }, Student { 1, "Joe", }, Student { 2, "Bob" } };

const Student* findStudentById(int id) {
    // Look through all the students
    for (auto& s: students) {
        // Return student with matching id
        if (s.id == id)
            return &s;
    }

    // No matching id found
    return nullptr;
}

int main() {
    constexpr std::string_view nobody { "nobody" };

    const Student* s1 { findStudentById(1) };
    std::cout << "You found: " << (s1 ? s1->name : nobody) << '\n';

    const Student* s2 { findStudentById(3) };
    std::cout << "You found: " << (s2 ? s2->name : nobody) << '\n';

    return 0;
}