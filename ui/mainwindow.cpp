#include "mainwindow.h"

#include "boardwidget.h"
#include "gamecontroller.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , controller_(new GameController(this))
    , boardWidget_(new BoardWidget(this))
{
    setCentralWidget(boardWidget_);
    setWindowTitle("Queens");

    // TODO: boardWidget_->setBoard(&controller_->board());
    // TODO: connect cellClicked -> controller, boardChanged -> update, solved -> win dialog
    // TODO: toolbar / layout with timer, size selector, buttons
}
