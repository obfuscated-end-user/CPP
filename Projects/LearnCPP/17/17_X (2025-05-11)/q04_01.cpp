// https://www.learncpp.com/cpp-tutorial/chapter-17-summary-and-quiz

/*
Alright, now let’s use our Card and Deck to implement a simplified version of Blackjack! If you’re not already familiar with Blackjack, the Wikipedia article for Blackjack has a summary.
Here are the rules for our version of Blackjack:
    The dealer gets one card to start (in real life, the dealer gets two, but one is face down so it doesn’t matter at this point).
    The player gets two cards to start.
    The player goes first.
    A player can repeatedly “hit” or “stand”.
    If the player “stands”, their turn is over, and their score is calculated based on the cards they have been dealt.
    If the player “hits”, they get another card and the value of that card is added to their total score.
    An ace normally counts as a 1 or an 11 (whichever is better for the total score). For simplicity, we’ll count it as an 11 here.
    If the player goes over a score of 21, they bust and lose immediately.
    When the player is done, it is the dealer’s turn.
    The dealer repeatedly draws until they reach a score of 17 or more, at which point they must stop drawing.
    If the dealer goes over a score of 21, they bust and the player wins immediately.
    Otherwise, if the player has a higher score than the dealer, the player wins. Otherwise, the player loses (we’ll consider ties as dealer wins for simplicity).
In our simplified version of Blackjack, we’re not going to keep track of which specific cards the player and the dealer have been dealt. We’ll only track the sum of the values of the cards they have been dealt for the player and dealer. This keeps things simpler.
Start with the code you wrote in the prior quiz (or use our reference solution).
> Step #1
Create a struct named Player that will represent a participant in our game (either the dealer or the player). Since in this game we only care about a player’s score, this struct only needs one member.
Write a function that will (eventually) play a round of Blackjack. For now, this function should draw one randomized card for the dealer and two randomized cards for the player. It should return a bool value indicating who has the greater score.
The code should output the following:

```
The dealer is showing: 10
You have score: 13
You win!

The dealer is showing: 10
You have score: 8
You lose!
```
*/

#include <algorithm>    // for std::shuffle
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

    static constexpr std::array allRanks { rank_ace, rank_2, rank_3, rank_4, rank_5, rank_6, rank_7, rank_8, rank_9, rank_10, rank_jack, rank_queen, rank_king };
    static constexpr std::array allSuits { suit_club, suit_diamond, suit_heart, suit_spade };

    Rank rank {};
    Suit suit {};

    friend std::ostream& operator<<(std::ostream& out, const Card &card) {
        static constexpr std::array ranks { 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K' };
        static constexpr std::array suits { 'C', 'D', 'H', 'S' };

        out << ranks[card.rank] << suits[card.suit];
        return out;
    }

    int value() const {
        static constexpr std::array rankValues { 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 };
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

bool playBlackJack() {
    Deck deck {};
    deck.shuffle();

    Player dealer { deck.dealCard().value() };
    std::cout << "The dealer is showing: " << dealer.score << '\n';

    Player player { deck.dealCard().value() + deck.dealCard().value() };
    std::cout << "You have score: " << player.score << '\n';

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