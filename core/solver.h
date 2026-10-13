#pragma once

#include <optional>
#include <vector>

#include "board.h"

namespace queens {

// Returns one queen per row: result[r] = column of the queen in row r.
// std::nullopt when the puzzle has no solution.
std::optional<std::vector<int>> solve(const Board &board);

// Counts solutions, stopping early once `limit` is reached.
// Use limit = 2 to check uniqueness.
int countSolutions(const Board &board, int limit = 2);

} // namespace queens
