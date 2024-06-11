// https://www.learncpp.com/cpp-tutorial/static-member-functions

// 複雑
#include <vector>

class MyClass {
public:
	static std::vector<char> s_mychars;

    // we're defining a nested class named init_static
	class init_static {
	public:
        // the init constructor will initialize our static variable
		init_static() {
			for (char ch{ 'a' }; ch <= 'z'; ++ch)
				s_mychars.push_back(ch);
		}
	};

private:
    // we'll use this static object to ensure the init_static constructor is called
	static init_static s_initializer;
};

// define our static member variable
std::vector<char> MyClass::s_mychars{};
// define our static initializer, which will call the init_static constructor, which will initialize s_mychars
MyClass::init_static MyClass::s_initializer{};