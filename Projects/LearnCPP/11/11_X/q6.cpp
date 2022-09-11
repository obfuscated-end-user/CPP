// https://www.learncpp.com/cpp-tutorial/chapter-11-comprehensive-quiz/

/*
Let’s pretend we’re writing a card game.

a) A deck of cards has 52 unique cards (13 card ranks of 4 suits). Create enumerations for the card ranks (2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King, Ace) and suits (clubs, diamonds, hearts, spades). Those enumerators will not be used to index arrays.

b) Each card will be represented by a struct named Card that contains a rank and a suit. Create the struct.

c) Create a printCard() function that takes a const Card reference as a parameter and prints the card rank and suit as a 2-letter code (e.g. the jack of spades would print as JS).

Hint: Use a switch-statement.

d) A deck of cards has 52 cards. Create an array (using std::array) to represent the deck of cards, and initialize it with one of each card. Do this in a function named createDeck and call createDeck from main. createDeck should return the deck to main.

Hint: Use static_cast if you need to convert an integer into an enumerated type.

e) Write a function named printDeck() that takes the deck as a const reference parameter and prints the cards in the deck. Use a range-based for-loop. When you can printDeck with the deck you generated in the previous task, the output should be

2C 3C 4C 5C 6C 7C 8C 9C TC JC QC KC AC 2D 3D 4D 5D 6D 7D 8D 9D TD JD QD KD AD 2H 3H 4H 5H 6H 7H 8H 9H TH JH QH KH AH 2S 3S 4S 5S 6S 7S 8S 9S TS JS QS KS AS

If you used different characters, that’s fine too.

f) Write a function named shuffleDeck to shuffle the deck of cards using std::shuffle. Update your main function to shuffle the deck and print out the shuffled deck.

Reminder: Only seed your random number generator once.

g) Write a function named getCardValue() that returns the value of a Card (e.g. a 2 is worth 2, a ten, jack, queen, or king is worth 10. Assume an Ace is worth 11).

There's nothing wrong if you give up. Do it, motherfucker.
*/

// a) A deck of cards has 52 unique cards (13 card ranks of 4 suits). Create enumerations for the card ranks (2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King, Ace) and suits (clubs, diamonds, hearts, spades). Those enumerators will not be used to index arrays.

#include <iostream>
#include <array>

enum CardRank {
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
    max_rank
};

enum Suit {
    clubs,
    diamonds,
    hearts,
    spades,
    max_suit
};

// b) Each card will be represented by a struct named Card that contains a rank and a suit. Create the struct.
struct Card {
    CardRank cardRank {};
    Suit suit {};
};

// c) Create a printCard() function that takes a const Card reference as a parameter and prints the card rank and suit as a 2-letter code (e.g. the jack of spades would print as JS).
void printCard(const Card& card) {
    switch (card.cardRank) {
        case CardRank::rank_2:      std::cout << '2';   break;
        case CardRank::rank_3:      std::cout << '3';   break;
        case CardRank::rank_4:      std::cout << '4';   break;
        case CardRank::rank_5:      std::cout << '5';   break;
        case CardRank::rank_6:      std::cout << '6';   break;
        case CardRank::rank_7:      std::cout << '7';   break;
        case CardRank::rank_8:      std::cout << '8';   break;
        case CardRank::rank_9:      std::cout << '9';   break;
        case CardRank::rank_10:     std::cout << 'T';   break;  // T for "ten"
        case CardRank::rank_jack:   std::cout << 'J';   break;
        case CardRank::rank_queen:  std::cout << 'Q';   break;
        case CardRank::rank_king:   std::cout << 'K';   break;
        case CardRank::rank_ace:    std::cout << 'A';   break;
    }
    switch (card.suit) {
        case Suit::clubs:       std::cout << 'C';   break;
        case Suit::diamonds:    std::cout << 'D';   break;
        case Suit::hearts:      std::cout << 'H';   break;
        case Suit::spades:      std::cout << 'S';   break;
    }
}

// d) A deck of cards has 52 cards. Create an array (using std::array) to represent the deck of cards, and initialize it with one of each card. Do this in a function named createDeck and call createDeck from main. createDeck should return the deck to main.

// function with return type of std::array that has 52 Card objects
std::array<Card, 52> createDeck() {
    // fuck aliases let's try doing it without that
    std::array<Card, 52> deck {};   // the deck to fill cards with
    std::array<Card, 52>::size_type index = 0; // index
    // twisted fate's balls have 52 iterations
    for (int i = 0; i < deck.size(); ++i) {
        deck[i] = Card{};
    }
    return deck;
}   // YOU'RE NOT DONE YET

int main() {
    Card card1 {CardRank::rank_jack, Suit::spades};
    printCard(card1);
    return 0;
}