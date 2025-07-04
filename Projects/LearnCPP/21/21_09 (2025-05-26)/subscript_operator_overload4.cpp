// https://www.learncpp.com/cpp-tutorial/overloading-the-subscript-operator

#include <iostream>
#include <utility>	// for std::as_const

class IntList {
private:
	int m_list[10] { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };	// give this class some initial state for this example

public:
	// C++23
	// Use an explicit object parameter (self) and auto&& to differentiate const vs non-const
	auto&& operator[](this auto&& self, int index) {
		// Complex code goes here
		return self.m_list[index];
	}

	const int& operator[](int index) const {
		return m_list[index];
	}
};

int main() {
	IntList list {};
	list[2] = 3;	// okay: calls non-const version of operator[]
	std::cout << list[2] << '\n';

	const IntList clist {};
	// clist[2] = 3;	// compile error: clist[2] returns const reference, which we can't assign to
	std::cout << clist[2] << '\n';

	return 0;
}

//	cd "c:\Users\Hello\Desktop\files\ZZZ_E_Drive\Projects\CPP\Projects\LearnCPP\21\21_09 (2025-05-26)\" ; if ($?) { g++ -std=c++23 "subscript_operator_overload4.cpp" -o "subscript_operator_overload4" } ; if ($?) { & ".\subscript_operator_overload4" }