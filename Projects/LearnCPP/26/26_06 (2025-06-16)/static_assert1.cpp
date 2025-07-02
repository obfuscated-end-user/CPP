// https://www.learncpp.com/cpp-tutorial/partial-template-specialization-for-pointers

#include <iostream>
#include <type_traits>  // for std::is_pointer_v and std::is_null_pointer_v

template <typename T>
class Storage {
	// Make sure T isn't a pointer or a std::nullptr_t
	static_assert(!std::is_pointer_v<T> && !std::is_null_pointer_v<T>, "Storage<T*> and Storage<nullptr> disallowed");

private:
	T m_value {};

public:
	Storage(T value) : m_value { value } {}

	void print() {
		std::cout << m_value << '\n';
	}
};

int main() {
	double d { 1.2 };

	Storage s1 { d };	// ok
	s1.print();

	Storage s2 { &d };  // static_assert because T is a pointer
	s2.print();

	Storage s3 { nullptr }; // static_assert because T is a nullptr
	s3.print();

	return 0;
}