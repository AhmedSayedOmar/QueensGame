#include <QtTest>

#include "core/solver.h"

using namespace queens;

class SolverTest : public QObject
{
    Q_OBJECT
private slots:
    void solvesKnownPuzzle();
    void countsUniqueSolution();
    void detectsUnsolvable();
};

void SolverTest::solvesKnownPuzzle()
{
    // TODO
    QSKIP("not written yet");
}

void SolverTest::countsUniqueSolution()
{
    // TODO: countSolutions(board, 2) == 1
    QSKIP("not written yet");
}

void SolverTest::detectsUnsolvable()
{
    // TODO
    QSKIP("not written yet");
}

QTEST_APPLESS_MAIN(SolverTest)
#include "solver_test.moc"
