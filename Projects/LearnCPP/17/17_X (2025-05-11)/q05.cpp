// https://www.learncpp.com/cpp-tutorial/chapter-17-summary-and-quiz

/*
a) Describe how you could modify the above program to handle the case where aces can be equal to 1 or 11.

It’s important to note that we’re only keeping track of the sum of the cards, not which specific cards the user has.

One way would be to keep track of how many aces the player and the dealer got dealt (In the Player struct, as an integer). If either the player or dealer go over 21 and their ace counter is greater than zero, you can reduce their score by 10 (convert an ace from 11 points to 1 point) and decrement the ace counter. This can be done as many times as needed until the ace counter reaches zero.

b) In actual blackjack, if the player and dealer have the same score (and the player has not gone bust), the result is a tie and neither wins. Describe how you’d modify the above program to account for this.

Our version of playBlackjack() currently returns a bool indicating whether the player won or not. We’ll need to update this function to return three possibilities: Dealer win, Player win, tie. The best way to do this would be to define an enumeration for these three options, and have the function return the appropriate enumerator.

c) Extra credit: implement the above two ideas into your blackjack game. Note that you will need to show the dealer’s initial card and the player’s initial two cards so they know whether they have an ace or not.

Here’s a sample output:

```
The dealer is showing JH (10)
You are showing AH 7D (18)
(h) to hit, or (s) to stand: h
You were dealt JD. You now have: 18
(h) to hit, or (s) to stand: s
The dealer flips a 6C. They now have: 16
The dealer flips a AD. They now have: 17
You win!
```
*/

#include <algorithm>	// for std::shuffle
#include <array>
#include <cassert>
#include <iostream>
#include "Random.h"

namespace Settings {
	// Maximum score before losing.
	constexpr int bust { 21 };
	// Minimum score that the dealer has to have.
	constexpr int dealerStopsAt { 17 };
}

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

class Player {
private:
	int m_score {};
	int m_ace11Count { 0 }; // how many aces worth 11 points the player has

public:
	// We'll use a function to add the card to the player's score
	// Since we now need to count aces
	void addToScore(Card card) {
		m_score += card.value();
		if (card.rank == Card::rank_ace)
			++m_ace11Count; // aces start at 11 points
		consumeAces();
	}

	// Decrease aceCount by 1 and
	void consumeAces() {
		// If the player would bust, see if we can switch aces from 11 points to 1
		while (m_score > Settings::bust && m_ace11Count > 0) {
			m_score -= 10;
			--m_ace11Count;
		}
	}

	int score() {
		return m_score;
	}
};

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
	while (player.score() < Settings::bust && playerWantsHit()) {
		Card card { deck.dealCard() };
		player.addToScore(card);
		std::cout << "You were dealt " << card << ". You now have: " << player.score() << '\n';
	}

	if (player.score() > Settings::bust) {
		std::cout << "You went bust!\n";
		return true;
	}

	return false;
}

// Returns true if the dealer went bust. False otherwise.
bool dealerTurn(Deck& deck, Player& dealer) {
	while (dealer.score() < Settings::dealerStopsAt) {
		Card card { deck.dealCard() };
		dealer.addToScore(card);
		std::cout << "The dealer flips a " << card << ". They now have: " << dealer.score() << '\n';
	}

	if (dealer.score() > Settings::bust) {
		std::cout << "The dealer went bust!\n";
		return true;
	}

	return false;
}

enum class GameResult {
	playerWon,
	dealerWon,
	tie
};

GameResult playBlackJack() {
	Deck deck {};
	deck.shuffle();

	Player dealer {};
	Card card1 { deck.dealCard() };
	dealer.addToScore(card1);
	std::cout << "The dealer is showing: " << card1 << " (" << dealer.score() <<")\n";

	Player player {};
	Card card2 { deck.dealCard() };
	Card card3 { deck.dealCard() };
	player.addToScore(card2);
	player.addToScore(card3);
	std::cout << "You are showing: " << card2 << ' ' << card3 << " (" << player.score() <<")\n";

	if (playerTurn(deck, player))	// if player busted
		return GameResult::dealerWon;
	
	if (dealerTurn(deck, dealer))	// if dealer busted
		return GameResult::playerWon;

	if (player.score() == dealer.score())
		return GameResult::tie;

	return (player.score() > dealer.score() ? GameResult::playerWon : GameResult::dealerWon);
}

int main() {
	switch(playBlackJack()) {
		case GameResult::playerWon:
			std::cout << "You win!\n";
			return 0;
		case GameResult::dealerWon:
			std::cout << "You lose!\n";
			return 0;
		case GameResult::tie:
			std::cout << "It's a tie!\n";
			return 0;
	}

	return 0;
}