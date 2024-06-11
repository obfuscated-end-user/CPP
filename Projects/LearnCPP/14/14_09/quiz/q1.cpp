// https://www.learncpp.com/cpp-tutorial/overloading-the-subscript-operator

#include <algorithm>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

// read the instructions thoroughly next time
struct StudentGrade {   // struct, not a class
    std::string name;
    char grade;
};

class GradeMap {
private:
    std::vector<StudentGrade> m_map;

public:
    // GradeMap(std::vector<StudentGrade> map): m_map {map} {} // not needed lol

    char& operator[](std::string_view name);
};

// struct
char& GradeMap::operator[](std::string_view name) {
    // 3rd arg is a lambda
    auto found = std::find_if(m_map.begin(), m_map.end(), [&](const auto& student) {return student.name == name;});

    if (found != m_map.end())
        return found->grade;

    // otherwise, create a new StudentGrade for this student and add it to the end of our vector
    m_map.push_back({std::string{name}});
    // and return it
    return m_map.back().grade;
}

int main() {
	GradeMap grades{};

	grades["Joe"] = 'A';
	grades["Frank"] = 'B';

	std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
	std::cout << "Frank has a grade of " << grades["Frank"] << '\n';

	return 0;
}

// alt solution
/*
#include <iostream>
#include <map> // std::map
#include <string>

int main() {
	// std::map can be initialized
	std::map<std::string, char> grades {
		{ "Joe", 'A' },
		{ "Frank", 'B' }
	};

	// and assigned
	grades["Susan"] = 'C';
	grades["Tom"] = 'D';

	std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
	std::cout << "Frank has a grade of " << grades["Frank"] << '\n';

	return 0;
}
*/