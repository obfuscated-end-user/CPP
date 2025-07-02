// https://www.learncpp.com/cpp-tutorial/timing-your-code

#include <chrono>
#include <iostream>

class Timer {
private:
	// Type aliases to make accessing nested type easier
	using Clock = std::chrono::steady_clock;
	using Second = std::chrono::duration<double, std::ratio<1>>;

	std::chrono::time_point<Clock> m_beg { Clock::now() };

public:
	void reset() {
		m_beg = Clock::now();
	}

	double elapsed() const {
		return std::chrono::duration_cast<Second>(Clock::now() - m_beg).count();
	}
};

int main() {
	Timer t;

	// Code to time goes here

	std::cout << "Time elapsed: " << t.elapsed() << " seconds\n";
	
	return 0;
}