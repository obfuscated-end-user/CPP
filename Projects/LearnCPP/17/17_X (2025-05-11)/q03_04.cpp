// https://www.learncpp.com/cpp-tutorial/chapter-17-summary-and-quiz

/*
Next, let’s create our deck of cards. Create a class named Deck that contains a std::array of Cards. You can assume a deck is 52 Cards.

The Deck should have three functions:

First, the default constructor should initialize the array of cards. You can use a ranged-for loop similar to the one in the main() function of the prior example to traverse through all the suits and ranks.

Second, add a dealCard() function that returns the next card in the Deck by value. Since std::array is a fixed-size array, think about how you will keep track of where the next card is. This function should assert out if it is called when the Deck has gone through all the cards.

Third, write a shuffle() member function that shuffles the deck. To make this easy, we will enlist the help of std::shuffle:

```
#include <algorithm> // for std::shuffle
#include "Random.h"  // for Random::mt

	// Put this line in your shuffle function to shuffle m_cards using the Random::mt Mersenne Twister
	// This will rearrange all the Cards in the deck randomly
	std::shuffle(m_cards.begin(), m_cards.end(), Random::mt);
```

The shuffle() function should also reset however you are tracking where the next card is back to the start of the deck.

The following program should run:

```
int main()
{
	Deck deck{};
	std::cout << deck.dealCard() << ' ' << deck.dealCard() << ' ' << deck.dealCard() << '\n';

	deck.shuffle();
	std::cout << deck.dealCard() << ' ' << deck.dealCard() << ' ' << deck.dealCard() << '\n';

	return 0;
}
```

and produce the following output (the last 3 cards should be randomized):

```
AC 2C 3C
2H 7H 9C
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

int main() {
	Deck deck {};
	std::cout << deck.dealCard() << ' ' << deck.dealCard() << ' ' << deck.dealCard() << '\n';

	deck.shuffle();
	std::cout << deck.dealCard() << ' ' << deck.dealCard() << ' ' << deck.dealCard() << '\n';

	return 0;
}