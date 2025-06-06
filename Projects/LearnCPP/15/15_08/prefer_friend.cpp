// https://www.learncpp.com/cpp-tutorial/friend-non-member-functions

#include <iostream>

class Value {
private:
    int m_value {};

public:
    explicit Value(int v) : m_value { v } {}

    bool isEqualToMember(const Value& v) const;
    friend bool isEqualToNonmember(const Value& v1, const Value& v2);
};

bool Value::isEqualToMember(const Value& v) const {
    return m_value == v.m_value;
}

bool isEqualToNonmember(const Value& v1, const Value& v2) {
    return v1.m_value == v2.m_value;
}

int main() {
    Value v1 { 5 };
    Value v2 { 6 };
    
    std::cout << v1.isEqualToMember(v2) << '\n';
    std::cout << isEqualToNonmember(v1, v2) << '\n';

    return 0;
}