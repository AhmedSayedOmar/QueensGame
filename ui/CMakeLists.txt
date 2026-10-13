add_library(queens_ui STATIC
    boardwidget.h    boardwidget.cpp
    gamecontroller.h gamecontroller.cpp
    mainwindow.h     mainwindow.cpp
)

target_include_directories(queens_ui PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_link_libraries(queens_ui PUBLIC queens_core Qt6::Widgets)
