#include "solver.h"

namespace queens {

std::optional<std::vector<int>> solve(const Board &board)
{
    // TODO: backtracking, one queen per row, track used columns/regions
    (void)board;
    return std::nullopt;
}

int countSolutions(const Board &board, int limit)
{
    // TODO: same search as solve(), but count and stop at `limit`
    (void)board; (void)limit;
    return 0;
}

} // namespace queens
