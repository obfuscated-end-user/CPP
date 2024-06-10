// https://www.learncpp.com/cpp-tutorial/introduction-to-program-defined-user-defined-types

#ifndef FRACTION_H
#define FRACTION_H

// Define a new type named Fraction
// This only defines what a Fraction looks like, it doesn't create one
// Note that this is a full definition, not a forward declaration
struct Fraction {
	int numerator {};
	int denominator {};
};

#endif