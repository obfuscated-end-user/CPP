// https://www.learncpp.com/cpp-tutorial/chapter-14-project

#include <array>
#include <cassert>
#include <chrono>
#include <iostream>
#include <numeric>
#include <random>

constexpr int g_consolelines = 25;

namespace Random {
    inline std::mt19937 generate() {
        std::random_device rd;
        std::seed_seq ss {
            static_cast<std::seed_seq::result_type>(std::chrono::steady_clock::now().time_since_epoch().count()),
            rd(), rd(), rd(), rd(), rd(), rd(), rd()
        };
        return std::mt19937 {ss};
    }

    inline std::mt19937 mt = generate();

    inline int get(int min, int max) {
        return std::uniform_int_distribution{min, max}(mt);
    }

    template <typename T>
    inline T get(T min, T max) {
        return std::uniform_int_distribution<T>{min, max}(mt);
    }

    template <typename R, typename S, typename T>
    inline R get(S min, T max) {
        return get<R>(static_cast<R>(min), static_cast<R>(max));
    }
}

class Direction {
public:
    enum Type {
        up,
        down,
        left,
        right,
        max_directions
    };
    
    Direction(Type type): m_type {type} {}

    Type getType() const {
        return m_type;
    }

    Direction operator-() const {
        switch (m_type) {
            case up:    return Direction {down};
            case down:  return Direction {up};
            case left:  return Direction {right};
            case right: return Direction {left};
        }
        assert(0 && "Unsupported direction was passed!");
        return Direction {up};
    }

    // Direction& dir doesn't work?
    friend std::ostream& operator<<(std::ostream& stream, Direction dir) {
        switch (dir.getType()) {
            case Direction::up:     return (stream << "up");
            case Direction::down:   return (stream << "down");
            case Direction::left:   return (stream << "left");
            case Direction::right:  return (stream << "right");
            default:                return (stream << "unknown direction");
        }
    }

    static Direction getRandomDirection() {
        Type random = static_cast<Type>(Random::get(0, Type::max_directions - 1));
        return Direction {random};
    }

// declare below else it won't work
private:
    Type m_type;
};

struct Point {
    int x;
    int y;

    friend bool operator==(Point p1, Point p2) {
        return p1.x == p2.x && p1.y == p2.y;
    }

    friend bool operator!=(Point p1, Point p2) {
        return !(p1 == p2);
    }

    Point getAdjacentPoint(Direction dir) const {
        switch (dir.getType()) {
            case Direction::up:     return Point {x, y - 1};
            case Direction::down:   return Point {x, y + 1};
            case Direction::left:   return Point {x - 1, y};
            case Direction::right:  return Point {x + 1, y};
        }
        return *this;
    }
};

namespace UserInput {
    bool isValidCommand(char ch) {
        // for now, use the grave accent (`), since i can't type "q" as of 2023/08/01 (i used the on-screen keyboard to type q)
        return ch == 'w' || ch == 'a' || ch == 's' || ch == 'd' || ch == '`';
    }

    void ignoreLine() {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    char getCharacter() {
        char operation;
        std::cin >> operation;
        ignoreLine();
        return operation;
    }

    char getCommandFromUser() {
        char ch;
        while(!isValidCommand(ch))
            ch = getCharacter();
        return ch;
    }

    Direction charToDirection(char ch) {
        switch (ch) {
            case 'w': return Direction {Direction::up};
            case 's': return Direction {Direction::down};
            case 'a': return Direction {Direction::left};
            case 'd': return Direction {Direction::right};
        }
        assert(0 && "Unsupported direction was passed!");
        return Direction {Direction::up};
    }
};

class Tile {
private:
    int m_num;

public:
    Tile() = default;
    explicit Tile(int num): m_num(num) {}

    friend std::ostream& operator<<(std::ostream& stream, Tile tile) {
        if (tile.m_num > 9)                             // if 2 digit number
            stream << " " << tile.m_num << " ";         // 1 space
        else if (tile.m_num > 0)                        // if 1 digit number
            stream << "  " << tile.m_num << " ";        // 2 spaces
        else if (tile.m_num == 0)                       // if empty
            stream << "    ";                           // 4 spaces
        return stream;
    }

    bool isEmpty() const {
        return m_num == 0;
    }

    int getNum() const {
        return m_num;
    }
};

class Board {
private:
    static constexpr int SIZE = 4;
    Tile m_tiles[SIZE][SIZE] {
        Tile {1},   Tile {2},   Tile {3},   Tile {4},
        Tile {5},   Tile {6},   Tile {7},   Tile {8},
        Tile {9},   Tile {10},  Tile {11},  Tile {12},
        Tile {13},  Tile {14},  Tile {15},  Tile {0}
    };

public:
    Board() = default;

    static void printEmptyLines(int count) {
        for (int i = 0; i < count; ++i)
            std::cout << '\n';
    }

    friend std::ostream& operator<<(std::ostream& stream, const Board& board) {
        printEmptyLines(g_consolelines);
        for (int y = 0; y < SIZE; ++y) {
            for (int x = 0; x < SIZE; ++x)
                stream << board.m_tiles[y][x];
            stream << '\n';
        }
        return stream;
    }

    Point getEmptyTilePos() const {
        for (int y = 0; y < SIZE; ++y)
            for (int x = 0; x < SIZE; ++x)
                if (m_tiles[y][x].isEmpty())
                    return {x, y};
        assert(0 && "There is no empty tile in the board!");
        return {-1, -1};
    }

    static bool isValidTilePos(Point pt) {
        return (pt.x >= 0 && pt.x < SIZE) && (pt.y >= 0 && pt.y < SIZE);
    }

    void swapTiles(Point pt1, Point pt2) {
        std::swap(m_tiles[pt1.y][pt1.x], m_tiles[pt2.y][pt2.x]);
    }

    friend bool operator==(const Board& f1, const Board& f2) {
        for (int y = 0; y < SIZE; ++y)
            for (int x = 0; x < SIZE; ++x)
                if (f1.m_tiles[y][x].getNum() != f2.m_tiles[y][x].getNum())
                    return false;
        return true;
    }

    bool moveTile(Direction dir) {
        Point emptyTile = getEmptyTilePos();
        Point adj = emptyTile.getAdjacentPoint(-dir);

        if (!isValidTilePos(adj))
            return false;
        
        swapTiles(adj, emptyTile);
        return true;
    }

    bool playerWon() const {
        static Board s_solved;
        return s_solved == *this;
    }

    void randomize() {
        for (int i = 0; i < 1000; ++i) {
            bool success = moveTile(Direction::getRandomDirection());
            if (!success)
                --i;
        }
    }
};

int main() {
    Board board {};
    board.randomize();
    std::cout << board;

    std::cout << "Enter a command: ";
    while (!board.playerWon()) {
        char ch = UserInput::getCommandFromUser();

        if (ch == '`') {    // quit
            std::cout << "\n\nBye!\n\n";
            return 0;
        }

        Direction dir = UserInput::charToDirection(ch);

        bool userMoved = board.moveTile(dir);
        if (userMoved)
            std::cout << board;
    }

    std::cout << "\n\nYou won!\n\n";
    return 0;
}

/* int main() {
    std::cout << std::boolalpha;
    std::cout << (Point{ 1, 1 }.getAdjacentPoint(Direction::up)    == Point{ 1, 0 }) << '\n';
    std::cout << (Point{ 1, 1 }.getAdjacentPoint(Direction::down)  == Point{ 1, 2 }) << '\n';
    std::cout << (Point{ 1, 1 }.getAdjacentPoint(Direction::left)  == Point{ 0, 1 }) << '\n';
    std::cout << (Point{ 1, 1 }.getAdjacentPoint(Direction::right) == Point{ 2, 1 }) << '\n';
    std::cout << (Point{ 1, 1 } != Point{ 2, 1 }) << '\n';
    std::cout << (Point{ 1, 1 } != Point{ 1, 2 }) << '\n';
    std::cout << !(Point{ 1, 1 } != Point{ 1, 1 }) << '\n';

    return 0;
} */

/* int main() {
    Board board{};
    std::cout << board;

    std::cout << "Generating random direction... " << Direction::getRandomDirection() << '\n';
    std::cout << "Generating random direction... " << Direction::getRandomDirection() << '\n';
    std::cout << "Generating random direction... " << Direction::getRandomDirection() << '\n';
    std::cout << "Generating random direction... " << Direction::getRandomDirection() << "\n\n";

    std::cout << "Enter a command: ";
    while (true) {
        char ch = UserInput::getCommandFromUser();

        // Handle non-direction commands
        if (ch == '`') {
            std::cout << "\n\nBye!\n\n";
            return 0;
        }

        // Handle direction commands
        Direction dir{ UserInput::charToDirection(ch) };

        std::cout << "You entered direction: " << dir << '\n';
    }

    return 0;
} */

/* int main() {
    Tile tile1{ 10 };
    Tile tile2{ 8 };
    Tile tile3{ 0 }; // the missing tile
    Tile tile4{ 1 };

    std::cout << "0123456789ABCDEF\n"; // to make it easy to see how many spaces are in the next line
    std::cout << tile1 << tile2 << tile3 << tile4 << '\n';

    std::cout << std::boolalpha << tile1.isEmpty() << ' ' << tile3.isEmpty() << '\n';
    std::cout << "Tile 2 has number: " << tile2.getNum() << "\nTile 4 has number: " << tile4.getNum() << '\n';

    Board board{};
    std::cout << board;

    return 0;
} */