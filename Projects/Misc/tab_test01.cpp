#include <iostream>

// 4 spaces
int main() {
    int rows {};
    std::cout << "enter number of rows: ";
    std::cin >> rows;

    for (int i { 1 }; i <= rows; ++i) { // comment tabbed but not 4 spaces away
        for (int j { 1 }; j <= rows - i; ++j) {
            std::cout << ' ';
        }

        for (int j { 1 }; j <= 2 * i; ++j) {
            std::cout << '*';
        }

        std::cout << '\n';
    }

    system("pause");

    return 0;
}