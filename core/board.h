#pragma once

#include <set>
#include <utility>
#include <vector>

namespace queens {

enum class CellState { Empty, Mark, Queen };

struct Cell {
    int row = 0;
    int col = 0;
    bool operator<(const Cell &o) const { return row != o.row ? row < o.row : col < o.col; }
    bool operator==(const Cell &o) const { return row == o.row && col == o.col; }
};

// An N x N grid split into N colored regions.
// regionId[r][c] is in [0, N). state[r][c] is what the player has placed.
class Board {
public:
    Board() = default;

    // regions must be square (N x N) with ids in [0, N).
    explicit Board(std::vector<std::vector<int>> regions);

    int size() const;
    int regionAt(int r, int c) const;
    CellState stateAt(int r, int c) const;

    void setState(int r, int c, CellState s);
    void cycleState(int r, int c);   // Empty -> Mark -> Queen -> Empty
    void clearQueensAndMarks();

    // Cells that break a rule (same row / column / region, or touching queens).
    // Only queens can conflict.
    std::set<Cell> conflicts() const;

    // True when N queens are placed and there are no conflicts.
    bool isSolved() const;
    
private:
    int n_ = 0;
    std::vector<std::vector<int>> regionId_;
    std::vector<std::vector<CellState>> state_;
    bool inBound(int row, int col) const;
};

} // namespace queens
