// https://www.learncpp.com/cpp-tutorial/overloading-the-comparison-operators

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Car {
private:
    std::string m_make;
    std::string m_model;

public:
    Car(std::string_view make, std::string_view model): m_make{make}, m_model{model} {}

    friend std::ostream& operator<< (std::ostream& out, const Car& car);
    friend bool operator< (const Car& c1, const Car& c2);
};

std::ostream& operator<< (std::ostream& out, const Car& car) {
    out << "(" << car.m_make << ", " << car.m_model << ')';
    return out;
}

bool operator<(const Car& c1, const Car& c2) {
    // how the fuck?
    // return (c1.m_make < c2.m_make && c1.m_model < c2.m_model)

    // if make is not the same, then compare the make
    if (c1.m_make != c2.m_make)
        return c1.m_make < c2.m_make;
    // else compare the model
    else
        return c1.m_model < c2.m_model;
}

int main() {
    std::vector<Car> cars {
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