// https://www.learncpp.com/cpp-tutorial/static-member-variables

#include <string_view>

class Whatever {
public:
    static const int s_value1 { 4 };    // a static const int can be defined and initialized directly
    static inline int s_value2 { 4 };   // a static inline variable can be defined and initialized directly

    static constexpr double s_value3 { 2.2 };   // ok
    static constexpr std::string_view s_view { "Hello" };   // this even works for classes that support constexpr initialization
};