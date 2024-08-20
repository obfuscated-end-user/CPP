// https://www.learncpp.com/cpp-tutorial/introduction-to-program-defined-user-defined-types

// Define a program-defined type named Fraction so the compiler understands what a Fraction is
// (we'll explain what a struct is and how to use them later in this chapter)
// This only defines what a Fraction type looks like, it doesn't create one
struct Fraction {
	int numerator {};
	int denominator {};
    int random_ass {};
};  // DON'T FORGET THE SEMICOLON

// Now we can make use of our Fraction type
int main() {
	Fraction f { 3, 4, 388 }; // this actually instantiates a Fraction object named f
	return 0;
}