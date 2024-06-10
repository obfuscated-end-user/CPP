// https://www.learncpp.com/cpp-tutorial/struct-aggregate-initialization

struct Rectangle {
    double length {};
    double width {};
};

int main() {
    const Rectangle unit { 1.0, 1.0 };
    const Rectangle zero { }; // value-initialize all members

    return 0;
}