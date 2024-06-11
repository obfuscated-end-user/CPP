// https://www.learncpp.com/cpp-tutorial/chapter-13-comprehensive-quiz

#include <algorithm> // std::shuffle
#include <array>
#include <cassert>
#include <ctime> // std::time
#include <iostream>
#include <random> // std::mt19937

class Card {
public:
    // correct
    enum Suit {
        club,
        diamond,
        heart,
        spade,
        max_suits
    };

    // correct
    enum Rank {
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

private:
    Rank m_rank;
    Suit m_suit;

public:
    Card() = default;
    Card(Rank rank, Suit suit):
        m_rank{rank}, m_suit{suit} {}

    void print() const {
        switch (m_rank) {
            case rank_2:      std::cout << '2';   break;
            case rank_3:      std::cout << '3';   break;
            case rank_4:      std::cout << '4';   break;
            case rank_5:      std::cout << '5';   break;
            case rank_6:      std::cout << '6';   break;
            case rank_7:      std::cout << '7';   break;
            case rank_8:      std::cout << '8';   break;
            case rank_9:      std::cout << '9';   break;
            case rank_10:     std::cout << 'T';   break;
            case rank_jack:   std::cout << 'J';   break;
            case rank_queen:  std::cout << 'Q';   break;
            case rank_king:   std::cout << 'K';   break;
            case rank_ace:    std::cout << 'A';   break;
            default:
                std::cout << '?';
                break;
        }

        switch (m_suit) {
            case club:       std::cout << 'C';   break;
            case diamond:    std::cout << 'D';   break;
            case heart:      std::cout << 'H';   break;
            case spade:      std::cout << 'S';   break;
            default:
                std::cout << '?';
                break;
        }
    }
    
    int value() const {
        switch (m_rank) {
            case rank_2:        return 2;
            case rank_3:        return 3;
            case rank_4:        return 4;
            case rank_5:        return 5;
            case rank_6:        return 6;
            case rank_7:        return 7;
            case rank_8:        return 8;
            case rank_9:        return 9;
            case rank_10:       return 10;
            case rank_jack:     return 10;
            case rank_queen:    return 10;
            case rank_king:     return 10;
            case rank_ace:      return 11;
            default:
                assert(false && "should never happen");
                return 0;
        }
    }
};

class Deck {
public:
    using DeckType = std::array<Card, 52>;
    using Index = DeckType::size_type;
private:
    DeckType m_deck {};

public:
    // Deck() = default;

    // this used to be createDeck
    Deck() {
        Index index = 0;

        for (int suit = 0; suit < Card::Suit::max_suits; ++suit) {
            for (int rank = 0; rank < Card::Rank::max_ranks; ++rank) {
                m_deck[index] = {static_cast<Card::Rank>(rank), static_cast<Card::Suit>(suit)};
                ++index;
            }
        }
    }

    void print() const {
        for (const auto& card : m_deck) {
            card.print();
            std::cout << ' ';
        }
        std::cout << '\n';
    }

    void shuffle() const {
        static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

        /// constexpr const Card *Deck::DeckType::begin() const noexcept
        std::shuffle(m_deck.begin(), m_deck.end(), mt);
    }
};
/* 
struct Player {
    int score;
};

using Deck = std::array<Card, 52>;
using Index = Deck::size_type;

// Maximum score before losing.
constexpr int g_maximumScore = 21;

// Minimum score that the dealer has to have.
constexpr int g_minimumDealerScore = 17;

bool playerWantsHit() {
    while (true) {
        std::cout << "(h) to hit, or (s) to stand: ";

        char ch;
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
bool playerTurn(const Deck& deck, Index& nextCardIndex, Player& player) {
    while (true) {
        if (player.score > g_maximumScore) {
            // This can happen even before the player had a choice if they drew 2
            // aces.
            std::cout << "You busted!\n";
            return true;
        }
        else {
            if (playerWantsHit()) {
                int cardValue =getCardValue(deck.at(nextCardIndex++));
                player.score += cardValue;
                std::cout << "You were dealt a " << cardValue << " and now have " << player.score << '\n';
            }
            else {
                // The player didn't go bust.
                return false;
            }
        }
    }
}

// Returns true if the dealer went bust. False otherwise.
bool dealerTurn(const Deck& deck, Index& nextCardIndex, Player& dealer) {
    // Draw cards until we reach the minimum value.
    while (dealer.score < g_minimumDealerScore) {
        int cardValue = getCardValue(deck.at(nextCardIndex++));
        dealer.score += cardValue;
        std::cout << "The dealer turned up a " << cardValue << " and now has " << dealer.score << '\n';
    }

    // If the dealer's score is too high, they went bust.
    if (dealer.score > g_maximumScore) {
        std::cout << "The dealer busted!\n";
        return true;
    }

    return false;
}

bool playBlackjack(const Deck& deck) {
    // Index of the card that will be drawn next. This cannot overrun
    // the array, because a player will lose before all cards are used up.
    Index nextCardIndex = 0;

    // Create the dealer and give them 1 card.
    Player dealer{ getCardValue(deck.at(nextCardIndex++)) };

    // The dealer's card is face up, the player can see it.
    std::cout << "The dealer is showing: " << dealer.score << '\n';

    // Create the player and give them 2 cards.
    Player player{ getCardValue(deck.at(nextCardIndex)) + getCardValue(deck.at(nextCardIndex + 1)) };
    nextCardIndex += 2;

    std::cout << "You have: " << player.score << '\n';

    if (playerTurn(deck, nextCardIndex, player)) {
        // The player went bust.
        return false;
    }

    if (dealerTurn(deck, nextCardIndex, dealer)) {
        // The dealer went bust, the player wins.
        return true;
    }

    return (player.score > dealer.score);
}

int main() {
    auto deck{ createDeck() };

    shuffleDeck(deck);

    if (playBlackjack(deck)) {
        std::cout << "You win!\n";
    } else {
        std::cout << "You lose!\n";
    }
    return 0;
} */

int main() {
    // 1st part
    const Card cardQueenHearts{ Card::rank_queen, Card::heart };
    cardQueenHearts.print();
    std::cout << " has the value " << cardQueenHearts.value() << '\n';

    // 2nd part
    Deck deck;
    deck.print();
    deck.shuffle();
    deck.print();
    return 0;
}

// i give up can't find out why it won't work
//  i need sleep