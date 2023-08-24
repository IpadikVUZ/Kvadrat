#include <stdio.h>
#include "SquareSolver.h"

void testsquaresolver(){
    testsolutionsquare();
    testsolutionline();
}

void testsolutionsquare(){
    double x1 =0, x2 = 0;
    int N=-1;
    
    testsolutionline();
    
    solutionsquare (1, 2, 3, &x1, &x2, &N);
    if ( (x1 == 0 && x2 ==0 && N == nosol) == false)
        printf ("Ошибка в solutionsquare, при a = 1, b = 2, c = 3. x1 должен быть равен 0, он равен %lf, x2 должен быть равен 0, он равен %lf, N должен быть равен 3, он равен %d \n", x1, x2, N);
        
    x1 =0, x2 = 0, N =-1;
    solutionsquare (1, 2, 1, &x1, &x2, &N);
    if ( (x1 == -1 && x2 ==0 && N == onesol) == false)
        printf ("Ошибка в solutionsquare, при a = 1, b = 2, c = 1. x1 должен быть равен -1, он равен %lf, x2 должен быть равен 0, он равен %lf, N должен быть равен 1, он равен %d \n", x1, x2, N);
        
    x1 =0, x2 = 0, N =-1;
    solutionsquare (1, 2, -3, &x1, &x2, &N);
    if ( (x1 == 1 && x2 ==-3 && N == twosol) == false)
        printf ("Ошибка в solutionsquare, при a = 1, b = 2, c = -3. x1 должен быть равен -1, он равен %lf, x2 должен быть равен -3, он равен %lf, N должен быть равен 0, он равен %d \n", x1, x2, N);
}

void testsolutionline(){
    double x1 =0;
    int N=-1;
    solutionline (0, 0, &x1, &N);
    if ( (x1 == 0 && N == infsol) == false )
        printf("Ошибка в solutionline, b = 0, c = 0. x1 должен быть равен 0, он равен %lf, N должен быть равен 2, он равен %d \n", x1, N);
        
    x1 =0, N =-1;
    solutionline (0, 2, &x1, &N);
    if ( (x1 == 0 && N == nosol) == false)
        printf("Ошибка в solutionline, b = 0, c = 2. x1 должен быть равен 0, он равен %lf, N должен быть равен 3, он равен %d \n", x1, N);
        
    x1 =0, N =-1;
    solutionline (1, 2, &x1, &N);
    if ( (x1 == -2 && N == onesol) == false )
        printf("Ошибка в solutionline, b = 1, c = 2. x1 должен быть равен -2, он равен %lf, N должен быть равен 1, он равен %d \n", x1, N);
}





