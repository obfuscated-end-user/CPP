// https://www.learncpp.com/cpp-tutorial/uncaught-exceptions-catch-all-handlers

#include <iostream>

struct GameSession {
	// Game session data here
};

void runGame(GameSession&) {
	throw 1;
}

void saveGame(GameSession&) {
	// Save user's game here
}

int main() {
	GameSession session {};

	try {
		runGame(session);
	} catch(...) {
		std::cerr << "Abnormal termination\n";
	}

	saveGame(session);	// save the user's game (even if catch-all handler was hit)

	return 0;
}