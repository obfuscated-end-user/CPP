class Something {
public:
	// Default constructor
	Something(int n = 0, double d = 1.2) { // allows us to construct a Something(int, double), Something(int), or Something()
        // empty function motherfucker
	}
};

int main() {
	Something s1 { 1, 2.4 }; // calls Something(int, double)
	Something s2 { 1 }; // calls Something(int, double)
	Something s3 {}; // calls Something(int, double)

	Something s4 { 2.4 }; // will not compile, as there's no constructor to handle Something(double)

	return 0;
}