// https://www.learncpp.com/cpp-tutorial/introduction-to-lambdas-anonymous-functions

#include <functional>
#include <iostream>

// Case 1: use a `std::function` parameter
void repeat1(int repetitions, const std::function<void(int)>& fn) {
	for (int i { 0 }; i < repetitions; ++i)
		fn(i);
}

// Case 2: use a function template with a type template parameter
template <typename T>
void repeat2(int repetitions, const T& fn) {
	for (int i { 0 }; i < repetitions; ++i)
		fn(i);
}

// Case 3: use the abbreviated function template syntax (C++20)
void repeat3(int repetitions, const auto& fn) {
	for (int i { 0 }; i < repetitions; ++i)
		fn(i);
}

// Case 4: use function pointer (only for lambda with no captures)
void repeat4(int repetitions, void (*fn)(int)) {
	for (int i { 0 }; i < repetitions; ++i)
		fn(i);
}

int main() {
	auto lambda = [](int i) {
		std::cout << i << '\n';
	};

	repeat1(3, lambda);
	repeat2(3, lambda);
	repeat3(3, lambda);
	repeat4(3, lambda);

	return 0;
}