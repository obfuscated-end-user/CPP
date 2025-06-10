// Nothing to see here.
// doesn't compile

#include <iostream>
#include <exception>
#include <typeinfo>

using namespace std;

class MyClass;

enum Color { Red, Green, Blue };
enum class Direction { Up, Down, Left, Right };

union Data {
    int i;
    float f;
};

template<typename T>
T add(T a, T b) {
    return a + b;
}

class Base {
public:
    virtual ~Base() = default;
};

class Derived : public Base {
public:
    void greet() { cout << "Hello\n"; }
};

class MyClass {
public:
    int x;

    MyClass(int val) : x(val) {}

    virtual void show() const {
        cout << "Value: " << x << '\n';
    }

    void constFunc() const {}
    static void staticFunc() {}
    inline void inlineFunc() {}

    mutable int mutableVar = 0;
};

int main() {
    register int reg = 1;
    volatile int vol = 2;
    const int c = 3;
    constexpr int cc = 4;
    static int st = 5;
    thread_local int tl = 6;

    // Control flow
    if (reg < vol) {
        cout << "if\n";
    } else if (reg == vol) {
        cout << "else if\n";
    } else {
        cout << "else\n";
    }

    switch (reg) {
        case 1: cout << "case 1\n"; break;
        default: cout << "default\n";
    }

    for (int i = 0; i < 1; ++i) {
        continue;
    }

    int j = 0;
    while (j < 1) {
        break;
    }

    do {
        break;
    } while (false);

    try {
        throw runtime_error("error");
    } catch (const exception& e) {
        cout << e.what() << '\n';
    }

    int* p = new int(10);
    delete p;

    Base* b = new Derived();
    Derived* d = dynamic_cast<Derived*>(b);

    if (d)
        d->greet();

    int i = 65;
    char cchar = static_cast<char>(i);
    long l = reinterpret_cast<long>(&i);
    const int* pc = &i;
    int* pnc = const_cast<int*>(pc);
    *pnc = 66;

    delete b;

    auto a = add(1, 2);
    using myint = int;
    myint mi = 7;

    int* np = nullptr;
    if (np == nullptr)
        cout << "nullptr\n";

    cout << "Size of int: " << sizeof(int) << '\n';
    std::cout << typeid(mi).name() << '\n';

    int* arr = new int[3]{1,2,3};
    delete[] arr;

    goto label;
    cout << "This will be skipped\n";
label:
    cout << "goto label\n";

    Direction dir = Direction::Up;
    (void)dir;

    Data data;
    data.i = 10;
    cout << "Union int: " << data.i << '\n';

    MyClass obj(42);
    obj.mutableVar = 5;
    obj.show();

    return 0;
}
