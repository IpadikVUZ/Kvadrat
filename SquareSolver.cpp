#include "SquareSolver.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>


int solutionsquare (double a, double b, double c, double *x1, double *x2){
    assert (isfinite (a));
    assert (isfinite (b));
    assert (isfinite (c));

    assert (x1 != NULL);
    assert (x2 != NULL);

    if (DCompare (a,0) == EQUAL) {
       return solutionline (b, c, x1);
    }
    else{
        double discriminant = b*b - 4*a*c;
        if (DCompare (discriminant,0) == EQUAL){
            *x1 = -b / (2*a);
            return ONESOL;
        }
        else if (DCompare (discriminant,0) == SECONDLARGER)
            return NOSOL;
        else{
            double sqrtd = sqrt(discriminant);
            *x1 = (-b + sqrtd) / (2*a);
            *x2 = (-b - sqrtd) / (2*a);
            return TWOSOL;
        }
    }
}

int solutionline (double b, double c, double *x1){
    assert (isfinite (b));
    assert (isfinite (c));
    assert (x1 != NULL);

     if (DCompare (b,0) == EQUAL){
         if (DCompare (c,0) == EQUAL)
                return INFSOL;
         else
                return NOSOL;
     }
     else{
            *x1 = -c / b;
            return ONESOL;
     }
}

void input (double *a, double *b, double *c){
    printf("Данная программа решает уравнения типа ax^2+bx+c=0 \n");
    printf ("Введите a:  ");
    getdouble (a);
    printf ("Введите b:  ");
    getdouble (b);
    printf ("Введите c:  ");
    getdouble (c);
}

void output (int SolCount, double x1, double x2){
    switch(SolCount){
        case TWOSOL:
           printf ("Два решения: %lf и %lf",x1,x2);
           break;
        case ONESOL:
           printf ("Одно решение %lf", x1);
           break;
        case INFSOL:
           printf ("Бесконечное количество решений");
           break;
        case NOSOL:
           printf ("Нет решений");
           break;
    }
}

int DCompare (double a, double b){
    double epsilon = 1e-30;
    if (fabs(a - b) < epsilon) return EQUAL;
    else if (a - b > epsilon) return FIRSTLARGER;
    else return SECONDLARGER;
}

void getdouble (double *a){
    while (scanf ("%lf", a)!=1){
          printf ("Ошибка ввода, попробуйте еще раз  ");
          clean();
    }
}

void clean(){
    while (getchar()!='\n') {;}
}
