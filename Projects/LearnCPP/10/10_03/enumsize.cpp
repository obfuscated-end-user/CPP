// https://www.learncpp.com/cpp-tutorial/unscoped-enumeration-input-and-output

#include <cstdint>

// Use an 8-bit unsigned integer as the enum base
enum Color : std::uint8_t {
    black,
    red,
    blue,
};