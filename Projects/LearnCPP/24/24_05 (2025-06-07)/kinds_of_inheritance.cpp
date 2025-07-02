// https://www.learncpp.com/cpp-tutorial/inheritance-and-access-specifiers

class Base {
public:
	int m_public {};
protected:
	int m_protected {};
private:
	int m_private {};
};

// Inherit from Base publicly
class Pub : public Base {};

// Inherit from Base protectedly
class Pro : protected Base {};

// Inherit from Base privately
class Pri : private Base {};

// Defaults to private inheritance
class Def : Base {};