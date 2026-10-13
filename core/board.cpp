#include "board.h"
#include <cstdlib>
namespace queens {
// regionID is tells the color of the grid cell 
Board::Board(std::vector<std::vector<int>> regions)
    : n_(static_cast<int>(regions.size())), regionId_(std::move(regions))
{
    //allocate state_ as n_ x n_ filled with CellState::Empty
    state_.assign(n_, std::vector<CellState>(n_, CellState::Empty));
}

int Board::size() const
{
    return n_;
}

int Board::regionAt(int r, int c) const
{
    // geting the grid cell color
    if (inBound(r,c)) {
        return regionId_[r][c];
    }
    return -1;
}

CellState Board::stateAt(int r, int c) const
{
    // TODO
    if (inBound(r,c)) {
        return state_[r][c];
    }
     return CellState::Empty;
}

void Board::setState(int r, int c, CellState s)
{
    // TODO
    if (inBound(r,c)) {
        state_[r][c] = s;
    }
}

void Board::cycleState(int r, int c)
{
    // TODO: Empty -> Mark -> Queen -> Empty
    if (inBound(r,c)) {
        if (state_[r][c] == CellState::Empty) {
            state_[r][c] = CellState::Mark;
        }
        else if (state_[r][c] == CellState::Mark) {
            state_[r][c] = CellState::Queen;
        }
        else if (state_[r][c] == CellState::Queen) {
            state_[r][c] = CellState::Empty;
        }
    }
}

void Board::clearQueensAndMarks()
{
    // TODO
    for (int i=0;i<size();i++){
        for (int j = 0; j < size(); j++) {
            state_[i][j] = CellState::Empty;
        }
    }
}

std::set<Cell> Board::conflicts() const
{ 
    // TODO: same row, same column, same region, or touching (incl. diagonal) queens
    std::vector <Cell> queenCells;
    std::set <Cell> clashCells;
    for (int i = 0; i < size(); i++) {
        for (int j = 0; j < size(); j++) {
            if (stateAt(i,j) == CellState::Queen) {
                queenCells.emplace_back(Cell{i,j});
            }
        }
    }
    for (Cell c : queenCells) {
        for (Cell d : queenCells) {
            if (c != d) {
                if (c.row == d.row) {
                    clashCells.insert(c);
                    clashCells.insert(d);
                }
                else if (c.col == d.col) {
                    clashCells.insert(c);
                    clashCells.insert(d);
                }
                else if (std::abs(c.row-d.row)<=1 && std::abs(c.col-d.col)<=1 ) {
                    clashCells.insert(c);
                    clashCells.insert(d);
                }
                else if (regionAt(c.row, c.col) == regionAt(d.row, d.col)) {
                    clashCells.insert(c);
                    clashCells.insert(d);
                }
            }
        }
    }
    return clashCells;
}

bool Board::isSolved() const
{
    int queenCount = 0;
    for (int i = 0; i < size(); i++) {
        for (int j = 0; j < size(); j++) {
            if (stateAt(i, j) == CellState::Queen) {
                queenCount++;
            }
        }
    }
    return (queenCount==size() && conflicts().empty() && size() != 0);
}
bool Board::inBound(int row, int col)const {
    if (row < size() && row >-1 && col < size() && col>-1) {
        return true;
    }
    return false;
}

} // namespace queens
