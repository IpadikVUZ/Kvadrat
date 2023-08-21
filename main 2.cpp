#include <stdio.h>
#include <cmath>

void clean(){
    while (getchar()!='\n') {;}
}

void getdouble (double *a){
    while (scanf ("%lf", &*a)!=1){
          printf ("Ошибка ввода, попробуйте еще раз  ");
          clean();
    }
    
}

void message (int n, double x1, double x2){
    switch(n){
        case 0: 
           printf ("Два решения: %lf %lf",x1,x2);
           break;
        case 1:
           printf ("Одно решение %lf", x1);
           break;
        case 2:
           printf ("Бесконечное количество решений");
           break;
        case 3:
           printf ("Нет решений");
           break;
    }
}

void solutionline (double b, double c, double *x1, int *N){
     if (b==0){
         if (c==0)
                *N=2;
         else
                *N=3;     
     }
     else{
            *N=1;
            *x1=-c/b;
     }      
}

void solutionsquare (double a, double b, double c, double *x1,  double *x2, int *N){
    if (a==0) {
       solutionline (b, c, &*x1, &*N);
    }
    else{
        double discriminant=b*b-4*a*c;
        if (discriminant==0){
            *N=1;
            *x1=-b/(2*a);
        }        
        else if (discriminant<0)
            *N=3;
        else{
            *N=0;
            *x1=(-b+sqrt(discriminant))/(2*a);
            *x2=(-b-sqrt(discriminant))/(2*a);        
        }         
    }
}

int main(){
    int N=0;
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0; // ax^2+bx+c=0
    printf ("Введите коэффицент 2-й степени:  ");
    getdouble (&a);
    printf ("Введите коэффицент 1-й степени:  ");
    getdouble (&b);
    printf ("Введите свободный член:  ");
    getdouble (&c);
    solutionsquare(a, b, c, &x1, &x2, &N);
    message(N, x1, x2);
}    