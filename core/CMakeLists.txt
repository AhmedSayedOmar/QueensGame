# Pure C++ library: do NOT link any Qt module here.
add_library(queens_core STATIC
    board.h     board.cpp
    solver.h    solver.cpp
    generator.h generator.cpp
)

# Lets other targets write #include "core/board.h"
target_include_directories(queens_core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
