// https://www.learncpp.com/cpp-tutorial/chapter-17-summary-and-quiz

/*
Next, let’s add some useful functions to our Card struct. First, overload operator<< to print the card rank and suit as a 2-letter code (e.g. the jack of spades would print as JS). You can do that by completing the following function:

```
struct Card
{
	// Your other stuff here

	friend std::ostream& operator<<(std::ostream& out, const Card &card)
	{
		out << // print your card rank and suit here
		return out;
	}
};
```

Second, add a function that returns the value of the Card. Treat an ace as value 11. Finally, add a std::array of Rank and of Suit (named allRanks and allSuits respectively) so they can be iterated over. Because these are part of a struct (not a namespace), make them static so they are only instantiated once (not with each object).

The following should compile:

```
int main()
{
	// Print one card
	Card card { Card::rank_5, Card::suit_heart };
	std::cout << card << '\n';

	// Print all cards
	for (auto suit : Card::allSuits)
		for (auto rank : Card::allRanks)
			std::cout << Card { rank, suit } << ' ';
	std::cout << '\n';

	return 0;
}
```

and produce the following output:

```
5H
AC 2C 3C 4C 5C 6C 7C 8C 9C TC JC QC KC AD 2D 3D 4D 5D 6D 7D 8D 9D TD JD QD KD AH 2H 3H 4H 5H 6H 7H 8H 9H TH JH QH KH AS 2S 3S 4S 5S 6S 7S 8S 9S TS JS QS KS
```
*/

#include <array>
#include <iostream>

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

	// These need to be static so they are only created once per program, not once per Card
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

int main() {
	// Print one card
	Card card { Card::rank_5, Card::suit_heart };
	std::cout << card << '\n';

	// Print all cards
	for (auto suit : Card::allSuits)
		for (auto rank : Card::allRanks)
			std::cout << Card { rank, suit } << ' ';
	std::cout << '\n';

	return 0;
}