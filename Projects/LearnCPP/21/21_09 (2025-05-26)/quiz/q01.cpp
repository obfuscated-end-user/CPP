// https://www.learncpp.com/cpp-tutorial/overloading-the-subscript-operator

/*
A map is a class that stores elements as a key-value pair. The key must be unique, and is used to access the associated pair. In this quiz, we’re going to write an application that lets us assign grades to students by name, using a simple map class. The student’s name will be the key, and the grade (as a char) will be the value.

a) First, write a struct named StudentGrade that contains the student’s name (as a std::string) and grade (as a char).

b) Add a class named GradeMap that contains a std::vector of StudentGrade named m_map.

c) Write an overloaded operator[] for this class. This function should take a std::string parameter, and return a reference to a char. In the body of the function, first see if the student’s name already exists (You can use std::find_if from <algorithm>). If the student exists, return a reference to the grade and you’re done. Otherwise, use the std::vector::emplace_back() or std::vector::push_back() function to add a StudentGrade for this new student. When you do this, std::vector will add a copy of your StudentGrade to itself (resizing if needed, invalidating all previously returned references). Finally, we need to return a reference to the grade for the student we just added to the std::vector. We can access the student we just added using the std::vector::back() function.

The following program should run:

```
#include <iostream>

// ...

int main()
{
	GradeMap grades{};

	grades["Joe"] = 'A';
	grades["Frank"] = 'B';

	std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
	std::cout << "Frank has a grade of " << grades["Frank"] << '\n';

	return 0;
}
```
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

struct StudentGrade {
    std::string name {};
    char grade {};
};

class GradeMap {
private:
    std::vector<StudentGrade> m_map {};

public:
    char& operator[](std::string_view name);
};

char& GradeMap::operator[](std::string_view name) {
    auto found { std::find_if(m_map.begin(), m_map.end(),
        [name](const auto& student) {   // this is a lambda that captures name from the surrounding scope
            return (student.name == name);  // so we can use name here
        })
    };

    if (found != m_map.end()) {
        return found->grade;
    }

    // otherwise create a new StudentGrade for this student and add
    // it to the end of our vector. Then return the grade.

    // emplace_back version (C++20 onward)
    // StudentGrade is an aggregate and emplace_back only works with aggregates as of C++20
    return m_map.emplace_back(std::string { name }).grade;

    // push_back version (C++17 or older)
    // m_map.push_back(StudentGrade{std::string{name}});
    // return m_map.back().grade;
}

int main() {
    GradeMap grades {};

    grades["Joe"] = 'A';
    grades["Frank"] = 'B';
    
    std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
    std::cout << "Frank has a grade of " << grades["Frank"] << '\n';

    return 0;
}