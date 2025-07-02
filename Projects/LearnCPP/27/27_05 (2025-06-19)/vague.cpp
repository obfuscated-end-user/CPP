// https://www.learncpp.com/cpp-tutorial/exceptions-classes-and-inheritance

class IntArray {
private:
	int m_length {};
	int* m_data {};

public:
	IntArray(int length)
		: m_length { length }, m_data { new int[length] } {}

	~IntArray() {
		delete[] m_data;
	}

	int getLength() {
		return m_length;
	}

	int& operator[](const int index);
};

int& IntArray::operator[](const int index) {
	if (index < 0 || index >= getLength())
		throw index;

	return m_data[index];
}

int main() {
	IntArray array { 5 };
	int index1 { 1 };
	int index2 { 2 };

	// Using the IntArray overloaded operator[] above
	try {
		int* value { new int { array[index1] + array[index2] } };
	} catch (int value) {
		// What are we catching here?
	}
	return 0;
}