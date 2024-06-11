// https://www.learncpp.com/cpp-tutorial/association

#include <string>

class Course {
private:
    std::string m_name;
    // Sometimes objects may have a relationship with other objects of the same type.
    const Course* m_prerequisite;

public:
    Course(const std::string& name, const Course* prerequisite=nullptr): m_name{name}, m_prerequisite{prerequisite} {}
};