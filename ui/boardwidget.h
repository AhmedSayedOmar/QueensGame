#pragma once

#include <QWidget>

#include "core/board.h"

// Draws the board and reports clicks. Holds no game rules.
class BoardWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BoardWidget(QWidget *parent = nullptr);

    void setBoard(const queens::Board *board);   // non-owning

signals:
    void cellClicked(int row, int col);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private:
    const queens::Board *board_ = nullptr;
    // TODO: helper to map a pixel position to (row, col)
};
