#include "gamecontroller.h"

GameController::GameController(QObject *parent)
    : QObject(parent)
{
    // TODO: start with queens::samplePuzzle(0)
}

const queens::Board &GameController::board() const
{
    return board_;
}

void GameController::newGame(int size)
{
    // TODO: board_ = queens::generate(size, seed); emit boardChanged();
    Q_UNUSED(size);
}

void GameController::cellClicked(int row, int col)
{
    // TODO: push undo, board_.cycleState(row, col), emit boardChanged(),
    //       emit solved() if board_.isSolved()
    Q_UNUSED(row);
    Q_UNUSED(col);
}

void GameController::undo()
{
    // TODO
}

void GameController::requestHint()
{
    // TODO: use queens::solve() to reveal one correct queen
}
