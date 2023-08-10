#include <cassert>
#include <iostream>

class Card
{
public:
    enum Suit
    {
        club,
        diamond,
        heart,
        spade,

        max_suits
    };

    enum Rank
    {
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
    Rank m_rank{};
    Suit m_suit{};

public:
    Card() = default;

    Card(Rank rank, Suit suit)
        : m_rank{ rank }, m_suit{ suit }
    {
    }

    void print() const
	{
		switch (m_rank)
		{
		case rank_2:        std::cout << '2';   break;
		case rank_3:        std::cout << '3';   break;
		case rank_4:        std::cout << '4';   break;
		case rank_5:        std::cout << '5';   break;
		case rank_6:        std::cout << '6';   break;
		case rank_7:        std::cout << '7';   break;
		case rank_8:        std::cout << '8';   break;
		case rank_9:        std::cout << '9';   break;
		case rank_10:       std::cout << 'T';   break;
		case rank_jack:     std::cout << 'J';   break;
		case rank_queen:    std::cout << 'Q';   break;
		case rank_king:     std::cout << 'K';   break;
		case rank_ace:      std::cout << 'A';   break;
		default:
            std::cout << '?';
            break;
		}

		switch (m_suit)
		{
		case club:          std::cout << 'C';   break;
		case diamond:       std::cout << 'D';   break;
		case heart:         std::cout << 'H';   break;
		case spade:         std::cout << 'S';   break;
		default:
            std::cout << '?';
            break;
		}
	}

    int value() const
    {
        switch (m_rank)
        {
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

int main()
{
    const Card cardQueenHearts{ Card::rank_queen, Card::heart};
    cardQueenHearts.print();
    std::cout << " has the value " << cardQueenHearts.value() << '\n';

    return 0;
}