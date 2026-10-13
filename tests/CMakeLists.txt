add_executable(board_test board_test.cpp)
target_link_libraries(board_test PRIVATE queens_core Qt6::Test)
add_test(NAME board_test COMMAND board_test)

add_executable(solver_test solver_test.cpp)
target_link_libraries(solver_test PRIVATE queens_core Qt6::Test)
add_test(NAME solver_test COMMAND solver_test)
