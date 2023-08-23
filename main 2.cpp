#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cassert>

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
    int N = 0; // Переменная, отвечающая за номер сообщения
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0; // ax^2+bx+c=0
    input (&a, &b, &c);
    solutionsquare (a, b, c, &x1, &x2, &N);
    output (N, x1, x2);
}    

//-----------------------------------------------------------------------------------
//! Решает кваратные уравнения ax^2+bx+c=0
//!
//! @param[in] a a-коэффицент
//! @param[in] b b-коэффицент
//! @param[in] c c-коэффицент
//! @param[out] x1 Указатель на первое решение
//! @param[out] x2 Указатель на второе решение
//! @param[out] N указатель на номер сообщения о кол-ве корней
//-----------------------------------------------------------------------------------

void solutionsquare (double a, double b, double c, double *x1, double *x2, int *N){
    
    assert (std::isfinite (a));
    assert (std::isfinite (b));
    assert (std::isfinite (c));
    
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

//-----------------------------------------------------------------------------------
//! Решает линейные уравнения bx+c=0
//!
//! @param[in] b b-коэффицент
//! @param[in] c c-коэффицент
//! @param[out] x1 Указатель на решение
//! @param[out] N указатель на номер сообщения о кол-ве корней
//-----------------------------------------------------------------------------------

void solutionline (double b, double c, double *x1, int *N){
    
    assert (std::isfinite (b));
    assert (std::isfinite (c));
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

//-----------------------------------------------------------------------------------
//! Функция для ввода трех переременных типа double
//!
//! @param[out] a Указатель на первое число
//! @param[out] b Указатель на второе число
//! @param[out] c Указатель на третье число
//-----------------------------------------------------------------------------------

void input (double *a, double *b, double *c){
    printf ("Введите коэффицент 2-й степени:  ");
    getdouble (&*a);
    printf ("Введите коэффицент 1-й степени:  ");
    getdouble (&*b);
    printf ("Введите свободный член:  ");
    getdouble (&*c);
}

//-----------------------------------------------------------------------------------
//! Функция для вывода сообщения о корнях
//!
//! @param[in] N номер сообщения
//! @param[in] x1 первый корень
//! @param[in] x2 второй корень
//-----------------------------------------------------------------------------------

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

//-----------------------------------------------------------------------------------
//! Функция для считывания числа типа double с консоли с проверкой ввода
//!
//! @param[out] a Указатель на переменную, в которую вводится число
//-----------------------------------------------------------------------------------

void getdouble (double *a){
    while (scanf ("%lf", &*a)!=1){
          printf ("Ошибка ввода, попробуйте еще раз  ");
          clean();
    }
}

//-----------------------------------------------------------------------------------
//! Функция для очистки буфера ввода
//-----------------------------------------------------------------------------------
void clean(){
    while (getchar()!='\n') {;}
}