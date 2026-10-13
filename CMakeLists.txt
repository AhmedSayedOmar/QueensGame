cmake_minimum_required(VERSION 3.21)
project(queens LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Test)

add_subdirectory(core)   # pure C++, no Qt
add_subdirectory(ui)     # Qt Widgets

add_executable(queens main.cpp)
target_link_libraries(queens PRIVATE queens_ui)

enable_testing()
add_subdirectory(tests)
