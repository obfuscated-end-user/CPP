// https://www.learncpp.com/cpp-tutorial/chapter-11-comprehensive-quiz

// YEEK YEEK WOOP WOOP WHY YOU CHEATING

#include <iostream>
#include <array>
#include <algorithm> // for std::shuffle
#include <ctime> // for std::time
#include <random> // for std::mt19937
#include <cassert>

/*
a) A deck of cards has 52 unique cards (13 card ranks of 4 suits). Create enumerations for the card ranks (2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King, Ace) and suits (clubs, diamonds, hearts, spades). Those enumerators will not be used to index arrays.
*/
enum class CardSuit {
    club,
    diamond,
    heart,
    spade,

    max_suits
};

enum class CardRank {
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
    rank_ace,

    max_ranks
};

// b) Each card will be represented by a struct named Card that contains a rank and a suit. Create the struct.

struct Card {
    CardRank rank{};
    CardSuit suit{};
};

/*
c) Create a printCard() function that takes a const Card reference as a parameter and prints the card rank and suit as a 2-letter code (e.g. the jack of spades would print as JS).

Hint: Use a switch-statement.
*/

void printCard(const Card& card) {
        switch (card.rank) {
            case CardRank::rank_2:      std::cout << '2';   break;
            case CardRank::rank_3:      std::cout << '3';   break;
            case CardRank::rank_4:      std::cout << '4';   break;
            case CardRank::rank_5:      std::cout << '5';   break;
            case CardRank::rank_6:      std::cout << '6';   break;
            case CardRank::rank_7:      std::cout << '7';   break;
            case CardRank::rank_8:      std::cout << '8';   break;
            case CardRank::rank_9:      std::cout << '9';   break;
            case CardRank::rank_10:     std::cout << 'T';   break;
            case CardRank::rank_jack:   std::cout << 'J';   break;
            case CardRank::rank_queen:  std::cout << 'Q';   break;
            case CardRank::rank_king:   std::cout << 'K';   break;
            case CardRank::rank_ace:    std::cout << 'A';   break;
            default:
                std::cout << '?';
                break;
    }

    switch (card.suit) {
        case CardSuit::club:       std::cout << 'C';   break;
        case CardSuit::diamond:    std::cout << 'D';   break;
        case CardSuit::heart:      std::cout << 'H';   break;
        case CardSuit::spade:      std::cout << 'S';   break;
        default:
            std::cout << '?';
            break;
    }
}

/*
d) A deck of cards has 52 cards. Create an array (using std::array) to represent the deck of cards, and initialize it with one of each card. Do this in a function named createDeck and call createDeck from main. createDeck should return the deck to main.

Hint: Use static_cast if you need to convert an integer into an enumerated type.
*/

// We'll need these many more times, create an aliases.
using deck_type = std::array<Card, 52>;
using index_type = deck_type::size_type;

deck_type createDeck() {
    deck_type deck{};

  // We could initialize each card individually, but that would be a pain.  Let's use a loop.
    index_type index{ 0 };
    for (int suit{ 0 }; suit < static_cast<int>(CardSuit::max_suits); ++suit) {
        for (int rank{ 0 }; rank < static_cast<int>(CardRank::max_ranks); ++rank) {
            deck[index].suit = static_cast<CardSuit>(suit);
            deck[index].rank = static_cast<CardRank>(rank);
            ++index;
        }
    }

    return deck;
}

/*
e) Write a function named printDeck() that takes the deck as a const reference parameter and prints the cards in the deck. Use a range-based for-loop. When you can printDeck with the deck you generated in the previous task, the output should be

2C 3C 4C 5C 6C 7C 8C 9C TC JC QC KC AC 2D 3D 4D 5D 6D 7D 8D 9D TD JD QD KD AD 2H 3H 4H 5H 6H 7H 8H 9H TH JH QH KH AH 2S 3S 4S 5S 6S 7S 8S 9S TS JS QS KS AS

If you used different characters, that’s fine too.
*/

void printDeck(const deck_type& deck) {
    for (const auto& card : deck) {
        printCard(card);
        std::cout << ' ';
    }

    std::cout << '\n';
}

/*
f) Write a function named shuffleDeck to shuffle the deck of cards using std::shuffle. Update your main function to shuffle the deck and print out the shuffled deck.

Reminder: Only seed your random number generator once.
*/

void shuffleDeck(deck_type& deck) {
    // mt is static so it only gets seeded once.
    static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
    std::shuffle(deck.begin(), deck.end(), mt);
}

/*
g) Write a function named getCardValue() that returns the value of a Card (e.g. a 2 is worth 2, a ten, jack, queen, or king is worth 10. Assume an Ace is worth 11).
*/

int getCardValue(const Card& card) {
    switch (card.rank) {
        case CardRank::rank_2:        return 2;
        case CardRank::rank_3:        return 3;
        case CardRank::rank_4:        return 4;
        case CardRank::rank_5:        return 5;
        case CardRank::rank_6:        return 6;
        case CardRank::rank_7:        return 7;
        case CardRank::rank_8:        return 8;
        case CardRank::rank_9:        return 9;
        case CardRank::rank_10:       return 10;
        case CardRank::rank_jack:     return 10;
        case CardRank::rank_queen:    return 10;
        case CardRank::rank_king:     return 10;
        case CardRank::rank_ace:      return 11;
        default:
            assert(false && "should never happen");
            return 0;
    }
}

int main() {
    auto deck{ createDeck() };
    shuffleDeck(deck);
    printDeck(deck);

    return 0;
}