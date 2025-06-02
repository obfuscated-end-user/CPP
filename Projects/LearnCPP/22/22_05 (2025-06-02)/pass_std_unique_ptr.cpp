// https://www.learncpp.com/cpp-tutorial/stdunique_ptr

#include <iostream>
#include <memory>   // for std::unique_ptr
#include <utility>  // for std::move

class Resource {
public:
    Resource() {
        std::cout << "Resource acquired\n";
    }

    ~Resource() {
        std::cout << "Resource destroyed\n";
    }
};

std::ostream& operator<<(std::ostream& out, const Resource&) {
    out << "I am a resource";
    return out;
}

// This function takes ownership of the Resource, which isn't what we want
void takeOwnership(std::unique_ptr<Resource> res) {
    if (res)
        std::cout << *res << '\n';
}   // the Resource is destroyed here

int main() {
    auto ptr { std::make_unique<Resource>() };

//  takeOwnership(ptr); // This doesn't work, need to use move semantics
    takeOwnership(std::move(ptr));  // ok: use move semantics

    std::cout << "Ending program\n";

    return 0;
}