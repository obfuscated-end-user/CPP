// https://www.learncpp.com/cpp-tutorial/friend-functions-and-classes/

class Accumulator {
private:
    int m_value { 0 };

public:
    void add(int value) {
        m_value += value;
    }

    // Make the reset() function a friend of this class
    friend void reset(Accumulator& accumulator);
};

// reset() is now a friend of the Accumulator class
void reset(Accumulator& accumulator) {
    // And can access the private data of Accumulator objects
    accumulator.m_value = 0;
}

int main() {
    Accumulator acc;
    acc.add(5); // add 5 to the accumulator
    reset(acc); // reset the accumulator to 0

    return 0;
}

// friend sounds like a stupid fucking keyword
// remember, this is different from the static function shit from the previous lessons

// a function declaration in class has a friend keyword
// some function outside the class suddenly has access to the private members of that class
// the Accumulator& accumulator thing seems necessary for it to be actually functional