#include "SquareSolver.h"
#include <stdio.h>

struct square_set{
    double a;
    double b;
    double c;
    double x1;
    double x2;
    int SolCount;
};

void testsquaresolver(){
    testsolutionsquare();
    testsolutionline();
}

void testsolutionsquare(){
    struct square_set solset[3] = {
    {1, 2, 3, 0, 0, NOSOL},
    {1, 2, 1, -1, 0, ONESOL},
    {1, 2, -3, 1, -3, TWOSOL}
    };

    for(int i=0;i<3;i++){
        double x1 = solset[i].x1;
        double x2 = solset[i].x2;
        int SolCount = -1;
        SolCount = solutionsquare (solset[i].a, solset[i].b, solset[i].c, &x1, &x2);
        if ( (x1 == solset[i].x1 && x2 == solset[i].x2 && SolCount == solset[i].SolCount) == false)
            printf ("Ошибка в solutionsquare, при a = %lf, b = %lf, c = %lf. x1 должен быть равен %lf, он равен %lf, x2 должен быть равен %lf, он равен %lf, SolCount должен быть равен %d, он равен %d \n \n", solset[i].a, solset[i].b, solset[i].c, solset[i].x1, x1, solset[i].x2, x2, solset[i].SolCount), SolCount;
    }
}

void testsolutionline(){
    struct square_set solset[3] = {
    {0, 0, 0, 0, 0, INFSOL},
    {0, 0, 2, 0, 0, NOSOL},
    {0, 1, 2, -2, 0, ONESOL}
    };

    for(int i=0;i<3;i++){
        double x1 = solset[i].x1;
        int SolCount=-1;
        SolCount = solutionline (solset[i].b, solset[i].c, &x1);
        if ( (x1 == solset[i].x1 && SolCount == solset[i].SolCount) == false)
            printf ("Ошибка в solutionline, при b = %lf, c = %lf. x1 должен быть равен %lf, он равен %lf, SolCount должен быть равен %d, он равен %d \n \n", solset[i].b, solset[i].c, solset[i].x1, x1, solset[i].SolCount, SolCount);
    }
}




