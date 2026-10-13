#include "boardwidget.h"

#include <QMouseEvent>
#include <QPainter>

BoardWidget::BoardWidget(QWidget *parent)
    : QWidget(parent)
{
    setMinimumSize(300, 300);
}

void BoardWidget::setBoard(const queens::Board *board)
{
    board_ = board;
    update();
}

void BoardWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    // TODO: region colors, grid lines, queen / X icons, red highlight on conflicts
}

void BoardWidget::mousePressEvent(QMouseEvent *event)
{
    // TODO: map event->position() to (row, col), then emit cellClicked(row, col)
    Q_UNUSED(event);
}
