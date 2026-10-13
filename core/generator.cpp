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
    static const std::vector<std::vector<std::vector<int>>> puzzles={
        { {0,0,0,0,0},{1,0,0,0,2},{1,3,0,0,2},{3,3,4,4,2},{3,3,3,3,2} },
        { {0,1,1,1,2},{0,1,1,1,2},{3,3,1,2,2},{3,3,2,2,2},{4,4,4,2,2} },
        {{0,0,0,0,1},{0,0,0,1,1},{2,2,3,3,3},{2,2,2,3,3},{2,2,2,4,4}},
        {{0,0,1,1,2},{0,1,1,1,2},{1,1,1,1,2},{3,1,1,4,2},{3,3,3,4,4}}
    };
    return Board{puzzles[index%puzzles.size()]};
}

} // namespace queens
