// https://www.learncpp.com/cpp-tutorial/stdunique_ptr

#include <iostream>
#include <memory>	// for std::unique_ptr

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

// The function only uses the resource, so we'll accept a pointer to the resource, not a reference to the whole std::unique_ptr<Resource>
void useResource(const Resource* res) {
	if (res)
		std::cout << *res << '\n';
	else
		std::cout << "No resource\n";
}

int main() {
	auto ptr { std::make_unique<Resource>() };

	useResource(ptr.get()); // note: get() used here to get a pointr to the Resource

	std::cout << "Ending program\n";

	return 0;
}	// The Resource is destroyed here