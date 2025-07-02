// https://www.learncpp.com/cpp-tutorial/hiding-inherited-functionality

#include <iostream>

class A {
public:
	virtual void fun() {
		std::cout << "public A::fun()\n";
	}
};

class B : public A {
private:
	virtual void fun() {
		std::cout << "private B::fun()\n";
	}
};

int main() {
	B b {};
	b.fun();					// compile error: not allowed as B::fun() is private
	static_cast<A&>(b).fun();   // okay: A::fun() is public, resolves to private B::fun() at runtime

	return 0;
}