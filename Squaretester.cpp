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
    const int Test_Count = 3;
    struct Square_set SolSet[Test_Count] = {
    {.a = 1, .b = 2, .c = 3, .x1 = 0, .x2 = 0, .SolCount = NOSOL},
    {.a = 1, .b = 2, .c = 1, .x1 = -1, .x2 = 0, .SolCount = ONESOL},
    {.a = 1, .b = 2, .c = -3, .x1 = 1, .x2 = -3, .SolCount = TWOSOL}
    };

    for (int i = 0; i < Test_Count; i++){
        double x1 = SolSet[i].x1;
        double x2 = SolSet[i].x2;
        int SolCount = -1;

        SolCount = SolutionSquare (SolSet[i].a, SolSet[i].b, SolSet[i].c, &x1, &x2);

        if (( DCompare(x1,SolSet[i].x1) == EQUAL &&
             DCompare (x2,SolSet[i].x2) == EQUAL &&
             SolCount == SolSet[i].SolCount)== false)

            printf ("Ошибка в SolutionSquare, при a = %lf, b = %lf, c = %lf. x1 должен быть равен %lf, "
            "он равен %lf, x2 должен быть равен %lf, он равен %lf, SolCount должен быть равен %d,"
            " он равен %d \n \n",
            SolSet[i].a, SolSet[i].b, SolSet[i].c, SolSet[i].x1, x1, SolSet[i].x2, x2, SolSet[i].SolCount), SolCount;
    }
}

void TestSolutionLine(){
    const int Test_Count = 3;
    struct Square_set SolSet[Test_Count] = {
    {.a = 0, .b = 0, .c = 0, .x1 = 0, .x2 = 0, .SolCount = INFSOL},
    {.a = 0, .b = 0, .c = 2, .x1 = 0, .x2 = 0, .SolCount = NOSOL},
    {.a = 0, .b = 1, .c = 2, .x1 = -2, .x2 = 0, .SolCount = ONESOL}
    };

    for (int i = 0; i < Test_Count; i++){
        double x1 = SolSet[i].x1;
        int SolCount=-1;

        SolCount = SolutionLine (SolSet[i].b, SolSet[i].c, &x1);

        if (( DCompare (x1, SolSet[i].x1) == EQUAL &&
             SolCount == SolSet[i].SolCount) == false)
            printf ("Ошибка в SolutionLine, при b = %lf, c = %lf. x1 должен быть равен %lf, он равен %lf, "
            "SolCount должен быть равен %d, он равен %d \n \n",
            SolSet[i].b, SolSet[i].c, SolSet[i].x1, x1, SolSet[i].SolCount, SolCount);
    }
}




