// https://www.learncpp.com/cpp-tutorial/chapter-17-summary-and-quiz

/*
Let’s say we want to write a card game that uses a standard deck of cards. In order to do that, we’re going to need some way to represent those cards, and decks of cards. Let’s build that functionality.

We’ll use it in the next quiz question to actually implement a game.

A deck of cards has 52 unique cards (13 card ranks of 4 suits). Create enumerations for the card ranks (ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, jack, queen, king) and suits (clubs, diamonds, hearts, spades).
*/

// Because identifiers can't start with a number, we'll use a "rank_" prefix for these
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

// We'll also prefix these for consistency
enum Suit {
    suit_club,
    suit_diamond,
    suit_heart,
    suit_spade,

    max_suits
};
