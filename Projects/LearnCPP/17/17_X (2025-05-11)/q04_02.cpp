// https://www.learncpp.com/cpp-tutorial/chapter-17-summary-and-quiz

/*
Add a Settings namespace that contains two constants: the value above which the player busts, and the value where the dealer must stop drawing cards.
Add the logic that handles the dealer’s turn. The dealer will draw cards until they hit 17, then they must stop. If they bust, the player wins.
Here is some sample output:

```
The dealer is showing: 8
You have score: 9
The dealer flips a 4D. They now have: 12
The dealer flips a JS. They now have: 22
The dealer went bust!
You win!

The dealer is showing: 6
You have score: 13
The dealer flips a 3D. They now have: 9
The dealer flips a 3H. They now have: 12
The dealer flips a 9S. They now have: 21
You lose!

The dealer is showing: 7
You have score: 21
The dealer flips a JC. They now have: 17
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