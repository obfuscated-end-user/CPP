// https://www.learncpp.com/cpp-tutorial/struct-aggregate-initialization

struct Employee {
    int id {};
    int age {};
    double wage {};
};

int main() {
    Employee joe { 2, 28 }; // joe.wage will be value-initialized to 0.0
    Employee satan {}; // value-initialize all members

    return 0;
}