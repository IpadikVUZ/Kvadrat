#include "SquareSolver.h"
#include <stdio.h>

struct Square_set{
    double a;
    double b;
    double c;
    double x1;
    double x2;
    MESSAGE_SOLUTION SolCount;
};

void TestSquareSolver(){
    TestSolutionSquare();
    TestSolutionLine();
}

void TestSolutionSquare(){
    const int TEST_COUNT = 3;
    struct Square_set SolSet[TEST_COUNT] = {
    {.a = 1, .b = 2, .c = 3, .x1 = 0, .x2 = 0, .SolCount = NOSOL},
    {.a = 1, .b = 2, .c = 1, .x1 = -1, .x2 = 0, .SolCount = ONESOL},
    {.a = 1, .b = 2, .c = -3, .x1 = 1, .x2 = -3, .SolCount = TWOSOL}
    };

    for (int i = 0; i < TEST_COUNT; i++){
        double x1 = SolSet[i].x1;
        double x2 = SolSet[i].x2;
        int SolCount = SolutionSquare (SolSet[i].a, SolSet[i].b, SolSet[i].c, &x1, &x2);

        if ((DCompare (x1, SolSet[i].x1) == EQUAL &&
             DCompare (x2, SolSet[i].x2) == EQUAL &&
             SolCount == SolSet[i].SolCount)== false)

            fprintf (stderr," Ошибка в SolutionSquare, при a = %lf, b = %lf, c = %lf. x1 должен быть равен %lf, "
            "он равен %lf, x2 должен быть равен %lf, он равен %lf, SolCount должен быть равен %d,"
            " он равен %d \n \n ",
            SolSet[i].a, SolSet[i].b, SolSet[i].c, SolSet[i].x1, x1, SolSet[i].x2, x2, SolSet[i].SolCount, SolCount);
        else
            printf ("Тест %d в SolutionSquare пройден успешно \n", i);
    }
}

void TestSolutionLine(){
    const int TEST_COUNT = 3;
    struct Square_set SolSet[TEST_COUNT] = {
    {.a = 0, .b = 0, .c = 0, .x1 = 0, .x2 = 0, .SolCount = INFSOL},
    {.a = 0, .b = 0, .c = 2, .x1 = 0, .x2 = 0, .SolCount = NOSOL},
    {.a = 0, .b = 1, .c = 2, .x1 = -2, .x2 = 0, .SolCount = ONESOL}
    };

    for (int i = 0; i < TEST_COUNT; i++){
        double x1 = SolSet[i].x1;
        int SolCount = SolutionLine (SolSet[i].b, SolSet[i].c, &x1);

        if (( DCompare (x1, SolSet[i].x1) == EQUAL &&
             SolCount == SolSet[i].SolCount) == false)
            fprintf (stderr, "Ошибка в SolutionLine, при b = %lf, c = %lf. x1 должен быть равен %lf, он равен %lf, "
            "SolCount должен быть равен %d, он равен %d \n \n",
            SolSet[i].b, SolSet[i].c, SolSet[i].x1, x1, SolSet[i].SolCount, SolCount);

        else
            printf ("Тест %d в Solutionline пройден успешно \n", i);

    }
}




