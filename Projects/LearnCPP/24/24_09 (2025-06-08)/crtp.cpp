// https://www.learncpp.com/cpp-tutorial/multiple-inheritance
// https://en.cppreference.com/w/cpp/language/crtp.html

// The Curiously Recurring Template Pattern (CRTP)
template<class T>
class Mixin {
	// Mixin<T> can use template type parameter T to access members of Derived
	// via (static_cast<T*>(this))
};

class Derived : public Mixin<Derived> {};