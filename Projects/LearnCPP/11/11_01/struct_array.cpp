// https://www.learncpp.com/cpp-tutorial/arrays-part-i

struct Rectangle {
    int length{};
    int width{};
};

int main() {
    Rectangle rects[5]{}; // declare an array of 5 Rectangle
    rects[0].length = 24;

    return 0;
}