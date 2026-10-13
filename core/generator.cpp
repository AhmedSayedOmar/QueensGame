#include "generator.h"

namespace queens {

Board generate(int n, std::uint32_t seed)
{
    // TODO:
    //  1. random valid queen placement
    //  2. grow one region from each queen (random flood fill)
    //  3. countSolutions(board, 2) == 1 ? done : retry
    (void)n; (void)seed;
    return Board{};
}

Board samplePuzzle(int index)
{
    // TODO: hardcode a few region grids and return Board{regions}
    (void)index;
    return Board{};
}

} // namespace queens
