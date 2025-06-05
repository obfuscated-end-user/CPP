// https://www.learncpp.com/cpp-tutorial/association

#include <string>
#include <string_view>

class Course {
private:
    std::string m_name {};
    const Course* m_prerequisite {};

public:
    Course(std::string_view name, const Course* prerequisite=nullptr)
        : m_name { name }, m_prerequisite { prerequisite } {}
};