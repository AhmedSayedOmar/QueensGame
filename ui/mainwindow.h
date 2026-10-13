#pragma once

#include <QMainWindow>

class BoardWidget;
class GameController;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    GameController *controller_ = nullptr;
    BoardWidget *boardWidget_ = nullptr;
    // TODO: timer label + QTimer, size QComboBox, New / Undo / Hint buttons
};
