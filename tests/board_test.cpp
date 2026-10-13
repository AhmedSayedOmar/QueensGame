#include <QtTest>

#include "core/board.h"

using namespace queens;

class BoardTest : public QObject
{
    Q_OBJECT
private slots:
    void cycleStateOrder();
    void sameRowConflict();
    void sameColConflict();

    void adjacentDiagonalConflict();
    void validSolutionIsSolved();
};

void BoardTest::cycleStateOrder()
{
    // TODO: Empty -> Mark -> Queen -> Empty
    Board b({ {0,1,2},{1,1,2},{1,1,2} });
    QCOMPARE(b.stateAt(0, 0), CellState::Empty);
    b.cycleState(0,0);
    QCOMPARE(b.stateAt(0, 0), CellState::Mark);
    b.cycleState(0,0);
    QCOMPARE(b.stateAt(0, 0), CellState::Queen);
    b.cycleState(0,0);
    QCOMPARE(b.stateAt(0, 0), CellState::Empty);
}

void BoardTest::sameRowConflict()
{
    // TODO
    Board b({ {0,1,2},{1,1,2},{1,1,2} });
    b.setState(0,0,CellState::Queen);
    b.setState(0,2,CellState::Queen);
    std::set<Cell> test=b.conflicts();
    std::set<Cell> expected {{0,0},{0,2}};
    QCOMPARE(test,expected);
}
void BoardTest::sameColConflict()
{
    // TODO
    Board b({ {0,1,2},{1,1,2},{1,1,2} });
    b.setState(0,0,CellState::Queen);
    b.setState(2,0,CellState::Queen);
    std::set<Cell> test=b.conflicts();
    std::set<Cell> expected {{0,0},{2,0}};
    QCOMPARE(test,expected);
}

void BoardTest::adjacentDiagonalConflict()
{
    // TODO
    Board b({ {0,1,2},{1,1,2},{1,1,2} });
    b.setState(0,0,CellState::Queen);
    b.setState(1,0,CellState::Queen);
    std::set<Cell> test=b.conflicts();
    std::set<Cell> expected {{0,0},{1,0}};
    QCOMPARE(test,expected);
}

void BoardTest::validSolutionIsSolved()
{
    // TODO: hand-made board with a known solution
    Board b({ {0,0,0,0,0},{1,0,0,0,2},{1,3,0,0,2},{3,3,4,4,2},{3,3,3,3,2}});
    b.setState(2,0,CellState::Queen);
    b.setState(0,2,CellState::Queen);
    b.setState(1,4,CellState::Queen);
    b.setState(4,1,CellState::Queen);
    b.setState(3,3,CellState::Queen);
    QVERIFY(b.isSolved());
}

QTEST_APPLESS_MAIN(BoardTest)
#include "board_test.moc"
