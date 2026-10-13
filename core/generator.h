#pragma once

#include <cstdint>

#include "board.h"

namespace queens {

// Builds an n x n puzzle with exactly one solution.
// Pass a seed to get reproducible puzzles (handy for tests).
Board generate(int n, std::uint32_t seed);

// A few known-good puzzles to build the UI against before the generator works.
Board samplePuzzle(int index);

} // namespace queens
