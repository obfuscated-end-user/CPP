// https://www.learncpp.com/cpp-tutorial/class-templates

#ifndef PAIR_H
#define PAIR_H

template <typename T>
struct Pair {
    T first{};
    T second{};
};

template <typename T>
constexpr T max(Pair<T> p) {
    return (p.first > p.second ? p.first : p.second);
}

#endif