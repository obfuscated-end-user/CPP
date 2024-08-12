// https://www.learncpp.com/cpp-tutorial/object-sizes-and-the-sizeof-operator

#include <iomanip>
#include <iostream>

int main() {
    int foo;
    std::cout << std::left;
    std::cout << std::setw(16) << "bool:" << sizeof(bool) << " bytes\n";
    std::cout << std::setw(16) << "char:" << sizeof(char) << " bytes\n";
    std::cout << std::setw(16) << "wchar_t:" << sizeof(wchar_t) << " bytes\n";
    std::cout << std::setw(16) << "char16_t:" << sizeof(char16_t) << " bytes\n";
    std::cout << std::setw(16) << "char32_t:" << sizeof(char32_t) << " bytes\n";
    std::cout << std::setw(16) << "short:" << sizeof(short) << " bytes\n";
    std::cout << std::setw(16) << "int:" << sizeof(int) << " bytes\n";
    std::cout << std::setw(16) << "long:" << sizeof(long) << " bytes\n";
    std::cout << std::setw(16) << "long long:" << sizeof(long long) << " bytes\n";
    std::cout << std::setw(16) << "float:" << sizeof(float) << " bytes\n";
    std::cout << std::setw(16) << "double:" << sizeof(double) << " bytes\n";
    std::cout << std::setw(16) << "long double:" << sizeof(long double) << " bytes\n";
    std::cout << std::setw(16) << "foo:" << sizeof(foo) << " bytes\n";
    return 0;
}