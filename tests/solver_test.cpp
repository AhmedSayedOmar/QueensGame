#include <QtTest>

#include "core/solver.h"
#include "core/generator.h"
using namespace queens;

class SolverTest : public QObject
{
    Q_OBJECT
private slots:
    void solvesKnownPuzzle();
    void countsUniqueSolution(); 
    void detectsUnsolvable();
    void checkTwoSolutions();
    void checkMultipleSolutions();
};

void SolverTest::solvesKnownPuzzle()
{
    auto result = solve(samplePuzzle(2));
    QVERIFY(result.has_value());
    QCOMPARE(result,(std::vector{1,4,2,0,3}));
}

void SolverTest::countsUniqueSolution()
{
    auto result = solve(samplePuzzle(2));
    QVERIFY(result.has_value());
    QCOMPARE(countSolutions(samplePuzzle(2)),1);
}

void SolverTest::detectsUnsolvable()
{
    Board b({ {0,1,2},{1,1,2},{1,1,2} });
    QCOMPARE(solve(b), std::nullopt);
}
void SolverTest::checkTwoSolutions()
{
    Board b({{0,0,1,1},{0,0,1,1},{2,2,3,3},{2,2,3,3}});
    QCOMPARE(countSolutions(b,5),2);
}
void SolverTest::checkMultipleSolutions(){

    Board b({ {0,0,0,0,0}, {1,1,1,1,1}, {2,2,2,2,2},
             {3,3,3,3,3}, {4,4,4,4,4} });
    QCOMPARE(countSolutions(b, 100), 14);   // limit above the real count: all of them
    QCOMPARE(countSolutions(b, 5), 5);      // stops early at the limit
    QCOMPARE(countSolutions(b, 1), 1);
}
QTEST_APPLESS_MAIN(SolverTest)
#include "solver_test.moc"
