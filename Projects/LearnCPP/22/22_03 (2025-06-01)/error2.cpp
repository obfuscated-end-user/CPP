// https://www.learncpp.com/cpp-tutorial/move-constructors-and-move-assignment

#include <iostream>
#include <string>
#include <string_view>

class Name {
private:
    std::string m_name {};

public:
    Name(std::string_view name) : m_name { name } {}

    Name(const Name& name) = delete;
    Name& operator=(const Name& name) = default;

    Name(Name&& name) = delete;
    Name& operator=(Name&& name) = delete;

    const std::string& get() const {
        return m_name;
    }
};

Name getJoe() {
    Name joe { "Joe" };
    return joe; // error: Move constructor was deleted
}

int main() {
    Name n1 { getJoe() };

    std::cout << n1.get() << '\n';

    return 0;
}