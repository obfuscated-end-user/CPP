// https://www.learncpp.com/cpp-tutorial/chapter-13-comprehensive-quiz

#include <iostream>

class HelloWorld {
private:
	char* m_data{}; // c-type string

public:
	HelloWorld() {
		m_data = new char[14];
		const char* init{ "Hello, World!" };
		for (int i = 0; i < 14; ++i)
			m_data[i] = init[i];
	}

	~HelloWorld() {
        delete[] m_data; // string
        std::cout << "lol fuckin destroyed"; // proof
	}

	void print() const {
		std::cout << m_data << '\n';
	}

};

int main() {
	HelloWorld hello{};
	hello.print();

    return 0;
}