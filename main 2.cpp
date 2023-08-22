#include <stdio.h>
#include <cmath>

enum message{
    twosol = 0,
    onesol = 1,
    infsol = 2,
    nosol = 3
};

void solutionsquare (double a, double b, double c, double *x1,  double *x2, int *N);
void solutionline (double b, double c, double *x1, int *N);
void input (double *a, double *b, double *c);
void output (int n, double x1, double x2);
void getdouble (double *a);
void clean();

int main(){
    int N=0;
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0; // ax^2+bx+c=0
    input (&a,&b,&c);
    solutionsquare (a, b, c, &x1, &x2, &N);
    output (N, x1, x2);
}    

void solutionsquare (double a, double b, double c, double *x1,  double *x2, int *N){
    if (a==0) {
       solutionline (b, c, &*x1, &*N);
    }
    else{
        double discriminant=b*b-4*a*c;
        if (discriminant==0){
            *N=onesol;
            *x1=-b/(2*a);
        }        
        else if (discriminant<0)
            *N=nosol;
        else{
            *N=twosol;
            *x1=(-b+sqrt(discriminant))/(2*a);
            *x2=(-b-sqrt(discriminant))/(2*a);        
        }         
    }
}

void solutionline (double b, double c, double *x1, int *N){
     if (b==0){
         if (c==0)
                *N=infsol;
         else
                *N=nosol;     
     }
     else{
            *N=onesol;
            *x1=-c/b;
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

void output (int n, double x1, double x2){
    switch(n){
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
