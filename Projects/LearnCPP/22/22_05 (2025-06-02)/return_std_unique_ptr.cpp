// https://www.learncpp.com/cpp-tutorial/stdunique_ptr

#include <iostream>
#include <memory>   // for std::unique_ptr

class Resource {
public:
    Resource() {
        std::cout << "Resource acquired\n";
    }

    ~Resource() {
        std::cout << "Resource destroyed\n";
    }
};

std::unique_ptr<Resource> createResource() {
    return std::make_unique<Resource>();
}

int main() {
    auto ptr { createResource() };

    // do whatever

    return 0;
}