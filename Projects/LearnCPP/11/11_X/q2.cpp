// https://www.learncpp.com/cpp-tutorial/chapter-11-comprehensive-quiz

/*
Question #2

Write the following program: Create a struct that holds a student’s first name and grade (on a scale of 0-100). Ask the user how many students they want to enter. Create a std::vector to hold all of the students. Then prompt the user for each name and grade. Once the user has entered all the names and grade pairs, sort the list by grade (highest first). Then print all the names and grades in sorted order.

For the following input:

Joe
82
Terry
73
Ralph
4
Alex
94
Mark
88

The output should look like this:

Alex got a grade of 94
Mark got a grade of 88
Joe got a grade of 82
Terry got a grade of 73
Ralph got a grade of 4

You can assume that names don’t contain spaces and that input extraction doesn’t fail.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Create a struct that holds a student’s first name and grade (on a scale of 0-100).
struct Student {
    std::string firstName {};
    int grade {};
};

// for std::sort
bool higher (const Student& student1, const Student& student2) {
    return (student1.grade > student2.grade);
}

int main() {
    // Ask the user how many students they want to enter.
    int numberOfStudents;
    std::cout << "How many students: ";
    std::cin >> numberOfStudents;

    // Create a std::vector to hold all of the students.
    std::vector<Student> students{};
    students.resize(numberOfStudents);  // THIS IS IMPORTANT

    // Then prompt the user for each name and grade.
    for (int i = 0; i < numberOfStudents; ++i) {
        std::cout << "Student #" << i + 1 << '\n';
        std::cout << "First name: ";
        std::cin >> students[i].firstName;
        std::cout << "Grade: ";
        std::cin >> students[i].grade;
    }

    // Once the user has entered all the names and grade pairs, sort the list by grade (highest first).
    std::sort(students.begin(), students.end(), higher);

    // Then print all the names and grades in sorted order.
    std::cout << '\n';
    for (int i = 0; i < numberOfStudents; ++i)
        std::cout << students[i].firstName << " got a grade of " << students[i].grade << '\n';

    return 0;
}

/*
#include <algorithm> // std::sort
#include <cstddef> // std::size_t
#include <iostream>
#include <string>
#include <vector>

struct Student
{
  std::string name{};
  int grade{};
};

int getNumberOfStudents()
{
  int numberOfStudents{};

  do
  {
    std::cout << "How many students do you want to enter? ";
    std::cin >> numberOfStudents;
  } while (numberOfStudents <= 0);

  return numberOfStudents;
}

std::vector<Student> getStudents()
{
  using vector_type = std::vector<Student>;

  int numberOfStudents{ getNumberOfStudents() };

  // Create a vector with numberOfStudents elements.
  vector_type students(static_cast<vector_type::size_type>(numberOfStudents));

  int studentNumber{ 1 };

  for (auto& student : students)
  {
    std::cout << "Enter name #" << studentNumber << ": ";
    std::cin >> student.name;
    std::cout << "Enter grade #" << studentNumber << ": ";
    std::cin >> student.grade;

    ++studentNumber;
  }

  return students;
}

// Pass by reference to avoid slow copies.
bool compareStudents(const Student& a, const Student& b)
{
  return (a.grade > b.grade);
}

int main()
{
  auto students{ getStudents() };

  std::sort(students.begin(), students.end(), compareStudents);

  // Print out all the names
  for (const auto& student : students)
  {
    std::cout << student.name << " got a grade of " << student.grade << '\n';
  }

  return 0;
}
*/