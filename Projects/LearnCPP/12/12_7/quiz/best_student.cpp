// https://www.learncpp.com/cpp-tutorial/introduction-to-lambdas-anonymous-functions/

/*
Question #1

Create a struct Student that stores the name and points of a student. Create an array of students and use std::max_element to find the student with the most points, then print that student’s name. std::max_element takes the begin and end of a list, and a function that takes 2 parameters and returns true if the first argument is less than the second.

Given the following array

std::array<Student, 8> arr{
    { { "Albert", 3 },
    { "Ben", 5 },
    { "Christine", 2 },
    { "Dan", 8 }, // Dan has the most points (8).
    { "Enchilada", 4 },
    { "Francis", 1 },
    { "Greg", 3 },
    { "Hagrid", 5 } }
};

your program should print

Dan is the best student

*/

#include <iostream>
#include <array>
#include <string>
#include <algorithm>

// Create a struct Student that stores the name and points of a student.
struct Student {
    std::string name {};
    int points {};
};

int main() {
    // Create an array of students
    std::array <Student, 8> arr {
        { { "Albert", 3 },
        { "Ben", 5 },
        { "Christine", 2 },
        { "Dan", 8 }, // Dan has the most points (8).
        { "Enchilada", 4 },
        { "Francis", 1 },
        { "Greg", 3 },
        { "Hagrid", 5 } }
    };

    const auto bestStudent = std::max_element(arr.begin(), arr.end(),
                            [] (const Student& student1, const Student& student2) {
                                return (student1.points < student2.points);
                            } );
    std::cout << bestStudent->name << " is the best student";   // done just because it fucking works, even though it looks like shit
    return 0;
}

/*
if (student1.points > student2.points)
                                    return student1.name;
                                else
                                    return student2.name;
*/