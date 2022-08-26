// https://www.learncpp.com/cpp-tutorial/function-template-instantiation/

#ifndef MAX_H
#define MAX_H

template <typename T>
T max(T x, T y) {
    return (x > y) ? x : y;
}

#endif