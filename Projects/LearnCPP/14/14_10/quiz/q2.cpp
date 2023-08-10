// https://www.learncpp.com/cpp-tutorial/overloading-the-parenthesis-operator

#include <cassert>
#include <iostream>
#include <string>
#include <string_view>

class MyString {
private:
    std::string m_string;

public:
    MyString(const std::string& string = {}): m_string{string} {}

    MyString operator()(int start, int length) {
        assert(start >= 0);
        assert(start + length <= static_cast<int>(m_string.length()) && "MyString::operator(int, int): substring is out of range");

        return m_string.substr(static_cast<std::string::size_type>(start), static_cast<std::string::size_type>(length));
    }

    std::string_view substr(int start, int length) {
        assert(start >= 0);
        assert(start + length <= static_cast<int>(m_string.length()) && "MyString::operator(int, int): substring is out of range");

        return std::string_view{m_string}.substr(static_cast<std::string::size_type>(start), static_cast<std::string::size_type>(length));
    }

    friend std::ostream& operator<<(std::ostream& out, const MyString& s) {
        out << s.m_string;
        return out;
    }
};

int main() {
    MyString s { "Hello, world!" };
    std::cout << s.substr(7, 5) << '\n'; // start at index 7 and return 5 characters

    return 0;
}