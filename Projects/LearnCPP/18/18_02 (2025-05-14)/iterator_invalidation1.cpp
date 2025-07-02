// https://www.learncpp.com/cpp-tutorial/introduction-to-iterators

#include <vector>

int main() {
	std::vector v { 0, 1, 2, 3 };

	for (auto num : v) {	// implicitly iterates over v
		if (num % 2 == 0)
			v.push_back(num + 1);	// when this invalidates the iterators of v, undefined bbehavior will result
	}

	return 0;
}