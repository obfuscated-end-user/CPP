// https://www.learncpp.com/cpp-tutorial/introduction-to-lambdas-anonymous-functions

/*
Create a struct Student that stores the name and points of a student. Create an array of students and use std::max_element to find the student with the most points, then print that student’s name. std::max_element takes the begin and end of a list, and a function that takes 2 parameters and returns true if the first argument is less than the second.

Given the following array

```
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
```

your program should print

```
Dan is the best student
```

Hint:

```
#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

struct Student
{
  std::string_view name{};
  int points{};
};

int main()
{
  constexpr std::array<Student, 8> arr{
    { { "Albert", 3 },
      { "Ben", 5 },
      { "Christine", 2 },
      { "Dan", 8 },
      { "Enchilada", 4 },
      { "Francis", 1 },
      { "Greg", 3 },
      { "Hagrid", 5 } }
  };

  const auto best{
    std::max_element(arr.begin(), arr.end(), / * lambda * /) // returns an iterator
  };

  std::cout << best->name << " is the best student\n"; // must dereference iterator to get element

  return 0;
}
```
*/

#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

struct Student {
    std::string_view name {};
    int points {};
};

int main() {
    constexpr std::array<Student, 8> arr {
      { { "Albert", 3 },
        { "Ben", 5 },
        { "Christine", 2 },
        { "Dan", 8 },
        { "Enchilada", 4 },
        { "Francis", 1 },
        { "Greg", 3 },
        { "Hagrid", 5 } }
    };

    const auto best {   // returns an iterator
        std::max_element(arr.begin(), arr.end(), [](const auto& a, const auto& b) {
            return a.points < b.points;
        })
    };

    std::cout << best->name << " is the best student\n";    // must dereference iterator to get element

    return 0;
}