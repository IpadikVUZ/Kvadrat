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
        printf ("������ � solutionsquare, ��� a = 1, b = 2, c = 3. x1 ������ ���� ����� 0, �� ����� %lf, x2 ������ ���� ����� 0, �� ����� %lf, SolCount ������ ���� ����� 3, �� ����� %d \n", x1, x2, SolCount);

    x1 =0, x2 = 0, SolCount =-1;
    SolCount = solutionsquare (1, 2, 1, &x1, &x2);
    if ( (x1 == -1 && x2 ==0 && SolCount == ONESOL) == false)
        printf ("������ � solutionsquare, ��� a = 1, b = 2, c = 1. x1 ������ ���� ����� -1, �� ����� %lf, x2 ������ ���� ����� 0, �� ����� %lf, SolCount ������ ���� ����� 1, �� ����� %d \n", x1, x2, SolCount);

    x1 =0, x2 = 0, SolCount =-1;
    SolCount = solutionsquare (1, 2, -3, &x1, &x2);
    if ( (x1 == 1 && x2 ==-3 && SolCount == TWOSOL) == false)
        printf ("������ � solutionsquare, ��� a = 1, b = 2, c = -3. x1 ������ ���� ����� -1, �� ����� %lf, x2 ������ ���� ����� -3, �� ����� %lf, SolCount ������ ���� ����� 0, �� ����� %d \n", x1, x2, SolCount);
}

void testsolutionline(){
    double x1 =0;
    int SolCount=-1;
    SolCount = solutionline (0, 0, &x1);
    if ( (x1 == 0 && SolCount == INFSOL) == false )
        printf("������ � solutionline, b = 0, c = 0. x1 ������ ���� ����� 0, �� ����� %lf, SolCount ������ ���� ����� 2, �� ����� %d \n", x1, SolCount);

    x1 =0, SolCount =-1;
    SolCount = solutionline (0, 2, &x1);
    if ( (x1 == 0 && SolCount == NOSOL) == false)
        printf("������ � solutionline, b = 0, c = 2. x1 ������ ���� ����� 0, �� ����� %lf, SolCount ������ ���� ����� 3, �� ����� %d \n", x1, SolCount);

    x1 =0, SolCount =-1;
    SolCount = solutionline (1, 2, &x1);
    if ( (x1 == -2 && SolCount == ONESOL) == false )
        printf("������ � solutionline, b = 1, c = 2. x1 ������ ���� ����� -2, �� ����� %lf, SolCount ������ ���� ����� 1, �� ����� %d \n", x1, SolCount);
}





