// https://www.learncpp.com/cpp-tutorial/lambda-captures/

/*
Question #1

Which of the following variables can be used by the lambda in main without explicitly capturing them?
*/

int i{};
static int j{};

int getValue() {
    return 0;
}

int main() {
    int a{};
    constexpr int b{};
    static int c{};
    static constexpr int d{};
    const int e{};
    const int f{ getValue() };
    static const int g{};
    static const int h{ getValue() };

    [](){
        // Try to use the variables without explicitly capturing them.
        a;
        b;
        c;
        d;
        e;
        f;
        g;
        h;
        i;
        j;
    }();

    return 0;
}

// all of them but a and f, since they aren't constant nor static