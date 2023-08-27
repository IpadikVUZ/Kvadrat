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

    if (a == 0) {
       return solutionline (b, c, x1);
    }
    else{
        double discriminant = b*b - 4*a*c;
        if (discriminant == 0){
            *x1 = -b / (2*a);
            return ONESOL;
        }
        else if (discriminant < 0)
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

     if (b == 0){
         if (c==0)
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
    printf ("Введите коэффицент 2-й степени:  ");
    getdouble (a);
    printf ("Введите коэффицент 1-й степени:  ");
    getdouble (b);
    printf ("Введите свободный член:  ");
    getdouble (c);
}

void output (int SolCount, double x1, double x2){
    switch(SolCount){
        case TWOSOL:
           printf ("Два решения: %lf %lf",x1,x2);
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

void getdouble (double *a){
    while (scanf ("%lf", a)!=1){
          printf ("Ошибка ввода, попробуйте еще раз  ");
          clean();
    }
}

void clean(){
    while (getchar()!='\n') {;}
}
