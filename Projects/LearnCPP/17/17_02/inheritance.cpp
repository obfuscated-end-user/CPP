// https://www.learncpp.com/cpp-tutorial/basic-inheritance-in-c

#include <iostream>
#include <string>
#include <string_view>

class Person {
public:
    std::string m_name;
    int m_age;

    Person(std::string_view name="", int age=0): m_name { name }, m_age { age } {}

    const std::string& getName() const {
        return m_name;
    }
    int getAge() const {
        return m_age;
    }
};

// BaseballPlayer publicly inheriting Person
class BaseballPlayer : public Person {
public:
    double m_battingAverage;
    int m_homeRuns;

    BaseballPlayer(double battingAverage=0.0, int homeRuns=0): m_battingAverage { battingAverage }, m_homeRuns { homeRuns } {}
};

// Employee publicly inherits from Person
class Employee: public Person {
public:
    double m_hourlySalary;
    long m_employeeID;

    Employee(double hourlySalary=0.0, long employeeID=0): m_hourlySalary { hourlySalary }, m_employeeID { employeeID } {}

    void printNameAndSalary() const {
        std::cout << m_name << ": " << m_hourlySalary << '\n';
    }
};

// inherits both Employee and Person
class Supervisor: public Employee {
public:
    long m_overseesIDs[5];
};

int main() {
    BaseballPlayer mark {};
    mark.m_name = "Mark"; // remember, m_name is public
    std::cout << mark.getName() << '\n'; // use the getName() function we've acquired from the Person base class

    Employee frank { 20.25, 12345 };
    frank.m_name = "Frank";
    frank.printNameAndSalary();

    return 0;
}