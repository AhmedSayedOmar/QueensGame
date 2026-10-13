#pragma once

#include <QObject>

#include "core/board.h"

// Owns the Board and the game flow. Widgets talk to this, never to the solver directly.
class GameController : public QObject
{
    Q_OBJECT
public:
    explicit GameController(QObject *parent = nullptr);

    const queens::Board &board() const;

public slots:
    void newGame(int size);
    void cellClicked(int row, int col);
    void undo();
    void requestHint();

signals:
    void boardChanged();
    void solved();

private:
    queens::Board board_;
    // TODO: undo stack
};
