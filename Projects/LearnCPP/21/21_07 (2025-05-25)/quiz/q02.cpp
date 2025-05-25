// https://www.learncpp.com/cpp-tutorial/overloading-the-comparison-operators

/*
Add an overloaded operator<< and operator< to the Car class at the top of the lesson so that the following program compiles:

```
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main()
{
  std::vector<Car> cars{
    { "Toyota", "Corolla" },
    { "Honda", "Accord" },
    { "Toyota", "Camry" },
    { "Honda", "Civic" }
  };

  std::sort(cars.begin(), cars.end()); // requires an overloaded operator<

  for (const auto& car : cars)
    std::cout << car << '\n'; // requires an overloaded operator<<

  return 0;
}
```

This program should produce the following output:

```
(Honda, Accord)
(Honda, Civic)
(Toyota, Camry)
(Toyota, Corolla)
```

If you need a refresher on std::sort, we talk about it in lesson 18.1 -- Sorting an array using selection sort.
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

class Car {
private:
    std::string m_make;
    std::string m_model;

public:
    Car(std::string_view make, std::string_view model)
        : m_make { make }, m_model { model } {}

    friend bool operator==(const Car& c1, const Car& c2);
    friend bool operator!=(const Car& c1, const Car& c2);

    friend std::ostream& operator<<(std::ostream& out, const Car& c) {
        out << '(' << c.m_make << ", " << c.m_model << ')';
        return out;
    }

    // h/t to reader Olivier for the initial version of the function
    friend bool operator<(const Car& c1, const Car& c2) {
        if (c1.m_make != c2.m_make) // If the car is not the same make...
            return c1.m_make < c2.m_make; // ...then compare the make

        return c1.m_model < c2.m_model; // otherwise compare the model
    }
};

bool operator==(const Car& c1, const Car& c2) {
    return c1.m_make == c2.m_make && c1.m_model == c2.m_model;
}

bool operator!= (const Car& c1, const Car& c2) {
    return !operator==(c1, c2);
}

int main() {
    std::vector<Car> cars {
        { "Toyota", "Corolla" },
        { "Honda", "Accord" },
        { "Toyota", "Camry" },
        { "Honda", "Civic" }
    };

    std::sort(cars.begin(), cars.end()); // requires an overloaded Car::operator<

    for (const auto& car : cars)
        std::cout << car << '\n'; // requires an overloaded Car::operator<<

    return 0;
}