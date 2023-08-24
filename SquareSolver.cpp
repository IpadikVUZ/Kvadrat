#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include "SquareSolver.h"

void solutionsquare (double a, double b, double c, double *x1, double *x2, int *N){
    assert (isfinite (a));
    assert (isfinite (b));
    assert (isfinite (c));
    
    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);
    
    if (a == 0) {
       solutionline (b, c, &*x1, &*N);
    }
    else{
        double discriminant = b*b - 4*a*c;
        if (discriminant == 0){
            *N = onesol;
            *x1 = -b / (2*a);
        }        
        else if (discriminant < 0)
            *N = nosol;
        else{
            double sqrtd = sqrt(discriminant);
            *N = twosol;
            *x1 = (-b+sqrtd) / (2*a);
            *x2 = (-b-sqrtd) / (2*a);        
        }         
    }
}

void solutionline (double b, double c, double *x1, int *N){
    assert (isfinite (b));
    assert (isfinite (c));
    assert (x1 != NULL);
    
     if (b==0){
         if (c==0)
                *N = infsol;
         else
                *N = nosol;     
     }
     else{
            *N = onesol;
            *x1 = -c/b;
     }      
}

void input (double *a, double *b, double *c){
    printf ("Введите коэффицент 2-й степени:  ");
    getdouble (&*a);
    printf ("Введите коэффицент 1-й степени:  ");
    getdouble (&*b);
    printf ("Введите свободный член:  ");
    getdouble (&*c);
}

void output (int N, double x1, double x2){
    switch(N){
        case twosol: 
           printf ("Два решения: %lf %lf",x1,x2);
           break;
        case onesol:
           printf ("Одно решение %lf", x1);
           break;
        case infsol:
           printf ("Бесконечное количество решений");
           break;
        case nosol:
           printf ("Нет решений");
           break;
    }
}

void getdouble (double *a){
    while (scanf ("%lf", &*a)!=1){
          printf ("Ошибка ввода, попробуйте еще раз  ");
          clean();
    }
}

void clean(){
    while (getchar()!='\n') {;}
}