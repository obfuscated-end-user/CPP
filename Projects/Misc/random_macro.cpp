#include <iostream>

int main() {
    int what_the_fk[]  { __WINPTHREADS_VERSION, static_cast<long>(___lc_codepage_func), __ATOMIC_RELEASE };
    std::cout << __WINPTHREADS_VERSION << '\n';
    std::cout << ___lc_codepage_func << '\n';
    std::cout << __ATOMIC_RELEASE << '\n';
    std::cout << __cpp_lib_allocator_traits_is_always_equal << '\n';
    std::cout << __cpp_lib_integer_sequence << '\n';

    return 0;
}