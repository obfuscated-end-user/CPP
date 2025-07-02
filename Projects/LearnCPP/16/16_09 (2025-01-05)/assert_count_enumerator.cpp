// https://www.learncpp.com/cpp-tutorial/array-indexing-and-length-using-enumerators

#include <cassert>
#include <iostream>
#include <vector>

namespace Students {
	enum Names {
		kenny,		  // 0
		kyle,			// 1
		stan,			// 2
		butters,		// 3
		cartman,		// 4
		max_students	// 5
	};
}

int main() {
	std::vector testScores { 78, 94, 66, 77, 14 };

	// Ensure the number of test scores is the same as the number of students
	assert(std::size(testScores) == Students::max_students);
	// example as of 2025/01/05 says:
	// assert(std::size(testScores) == max_students);

	return 0;
}

// use a `static_assert` to ensure the length of your constexpr array matches your count enumerator
// use an `assert` to ensure the length of your non-constexpr array matches your count enumerator