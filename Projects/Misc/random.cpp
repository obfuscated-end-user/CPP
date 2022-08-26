// https://arvid.io/2018/06/30/on-cxx-random-number-generator-quality/

#include <random>
#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

template<class Rand, class T>
static void run() {
    std::random_device rd;
    Rand gen(rd());
    std::uniform_int_distribution<T> dis(0);

    T val;
    while (1) {
        val = dis(gen);
        fwrite((void *)&val, 1, sizeof(T), stdout);
    }
}

int main() {
    freopen(nullptr, "wb", stdout); /* only required for windows */
    run<std::ranlux24_base, uint32_t>();
    return 0;
}