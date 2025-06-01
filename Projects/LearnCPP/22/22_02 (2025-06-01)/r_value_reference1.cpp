// https://www.learncpp.com/cpp-tutorial/rvalue-references

int main() {
    int x { 5 };
    int& lref { x };    // l-value reference initialized with l-value x
    int&& rref { 5 };   // r-value reference initialized with r-value 5

    return 0;
}