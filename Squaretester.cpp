#include "SquareSolver.h"
#include <stdio.h>


void testsquaresolver(){
    testsolutionsquare();
    testsolutionline();
}

void testsolutionsquare(){
    double x1 =0, x2 = 0;
    int SolCount=-1;

    testsolutionline();

    SolCount = solutionsquare (1, 2, 3, &x1, &x2);
    if ( (x1 == 0 && x2 ==0 && SolCount == NOSOL) == false)
        printf ("Ошибка в solutionsquare, при a = 1, b = 2, c = 3. x1 должен быть равен 0, он равен %lf, x2 должен быть равен 0, он равен %lf, SolCount должен быть равен 3, он равен %d \n", x1, x2, SolCount);

    x1 =0, x2 = 0, SolCount =-1;
    SolCount = solutionsquare (1, 2, 1, &x1, &x2);
    if ( (x1 == -1 && x2 ==0 && SolCount == ONESOL) == false)
        printf ("Ошибка в solutionsquare, при a = 1, b = 2, c = 1. x1 должен быть равен -1, он равен %lf, x2 должен быть равен 0, он равен %lf, SolCount должен быть равен 1, он равен %d \n", x1, x2, SolCount);

    x1 =0, x2 = 0, SolCount =-1;
    SolCount = solutionsquare (1, 2, -3, &x1, &x2);
    if ( (x1 == 1 && x2 ==-3 && SolCount == TWOSOL) == false)
        printf ("Ошибка в solutionsquare, при a = 1, b = 2, c = -3. x1 должен быть равен -1, он равен %lf, x2 должен быть равен -3, он равен %lf, SolCount должен быть равен 0, он равен %d \n", x1, x2, SolCount);
}

void testsolutionline(){
    double x1 =0;
    int SolCount=-1;
    SolCount = solutionline (0, 0, &x1);
    if ( (x1 == 0 && SolCount == INFSOL) == false )
        printf("Ошибка в solutionline, b = 0, c = 0. x1 должен быть равен 0, он равен %lf, SolCount должен быть равен 2, он равен %d \n", x1, SolCount);

    x1 =0, SolCount =-1;
    SolCount = solutionline (0, 2, &x1);
    if ( (x1 == 0 && SolCount == NOSOL) == false)
        printf("Ошибка в solutionline, b = 0, c = 2. x1 должен быть равен 0, он равен %lf, SolCount должен быть равен 3, он равен %d \n", x1, SolCount);

    x1 =0, SolCount =-1;
    SolCount = solutionline (1, 2, &x1);
    if ( (x1 == -2 && SolCount == ONESOL) == false )
        printf("Ошибка в solutionline, b = 1, c = 2. x1 должен быть равен -2, он равен %lf, SolCount должен быть равен 1, он равен %d \n", x1, SolCount);
}





