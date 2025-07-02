// https://www.learncpp.com/cpp-tutorial/chapter-17-summary-and-quiz

/*
Finally, add logic for the player’s turn. This will complete the game.
Here is some sample output:

```
The dealer is showing: 2
You have score: 14
(h) to hit, or (s) to stand: h
You were dealt KH.  You now have: 24
You went bust!
You lose!

The dealer is showing: 10
You have score: 9
(h) to hit, or (s) to stand: h
You were dealt TH.  You now have: 19
(h) to hit, or (s) to stand: s
The dealer flips a 3D.  They now have: 13
The dealer flips a 7H.  They now have: 20
You lose!

The dealer is showing: 7
You have score: 12
(h) to hit, or (s) to stand: h
You were dealt 7S.  You now have: 19
(h) to hit, or (s) to stand: h
You were dealt 2D.  You now have: 21
(h) to hit, or (s) to stand: s
The dealer flips a 6H.  They now have: 13
The dealer flips a QC.  They now have: 23
The dealer went bust!
You win!
```
*/

#include <algorithm>	// for std::shuffle
#include <array>
#include <cassert>
#include <iostream>
#include "Random.h"

struct Card {
	enum Rank {
		rank_ace,
		rank_2,
		rank_3,
		rank_4,
		rank_5,
		rank_6,
		rank_7,
		rank_8,
		rank_9,
		rank_10,
		rank_jack,
		rank_queen,
		rank_king,

		max_ranks
	};

	enum Suit {
		suit_club,
		suit_diamond,
		suit_heart,
		suit_spade,

		max_suits
	};

	static constexpr std::array allRanks {
		rank_ace, rank_2, rank_3, rank_4, rank_5, rank_6, rank_7,
		rank_8, rank_9, rank_10, rank_jack, rank_queen, rank_king
	};
	static constexpr std::array allSuits {
		suit_club, suit_diamond,
		suit_heart, suit_spade
	};

	Rank rank {};
	Suit suit {};

	friend std::ostream& operator<<(std::ostream& out, const Card &card) {
		static constexpr std::array ranks {
			'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'
		};
		static constexpr std::array suits { 'C', 'D', 'H', 'S' };

		out << ranks[card.rank] << suits[card.suit];
		return out;
	}

	int value() const {
		static constexpr std::array rankValues {
			11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10
	};
		return rankValues[rank];
	}
};

class Deck {
private:
	std::array<Card, 52> m_cards {};
	std::size_t m_nextCardIndex { 0 };

public:
	Deck() {
		std::size_t count { 0 };
		for (auto suit : Card::allSuits)
			for (auto rank : Card::allRanks)
				m_cards[count++] = Card { rank, suit };
	}

	void shuffle() {
		std::shuffle(m_cards.begin(), m_cards.end(), Random::mt);
		m_nextCardIndex = 0;
	}

	Card dealCard() {
		assert(m_nextCardIndex != 52 && "Deck::dealCard ran out of cards.");
		return m_cards[m_nextCardIndex++];
	}
};

struct Player {
	int score {};
};

namespace Settings {
	// Maximum score before losing.
	constexpr int bust { 21 };
	// Minimum score that the dealer has to have.
	constexpr int dealerStopsAt { 17 };
}

bool playerWantsHit() {
	while (true) {
		std::cout << "(h) to hit, or (s) to stand: ";

		char ch {};
		std::cin >> ch;

		switch (ch) {
			case 'h':
				return true;
			case 's':
				return false;
		}
	}
}

// Returns true if the player went bust. False otherwise.
bool playerTurn(Deck& deck, Player& player) {
	while (player.score < Settings::bust && playerWantsHit()) {
		Card card { deck.dealCard() };
		player.score += card.value();
		std::cout << "You were dealt " << card << ". You now have: " << player.score << '\n';
	}

	if (player.score > Settings::bust) {
		std::cout << "You went bust!\n";
		return true;
	}

	return false;
}

// Returns true if the dealer went bust. False otherwise.
bool dealerTurn(Deck& deck, Player& dealer) {
	while (dealer.score < Settings::dealerStopsAt) {
		Card card { deck.dealCard() };
		dealer.score += card.value();
		std::cout << "The dealer flips a " << card << ". They now have: " << dealer.score << '\n';
	}

	if (dealer.score > Settings::bust) {
		std::cout << "The dealer went bust!\n";
		return true;
	}

	return false;
}

bool playBlackJack() {
	Deck deck {};
	deck.shuffle();

	Player dealer { deck.dealCard().value() };
	std::cout << "The dealer is showing: " << dealer.score << '\n';

	Player player { deck.dealCard().value() + deck.dealCard().value() };
	std::cout << "You have score: " << player.score << '\n';

	if (playerTurn(deck, player))
		return true;
	
	if (dealerTurn(deck, dealer))
		return true;

	return (player.score > dealer.score);
}

int main() {
	if (playBlackJack()) {
		std::cout << "You win!\n";
	} else {
		std::cout << "You lose!\n";
	}

	return 0;
}