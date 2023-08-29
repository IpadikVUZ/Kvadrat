#include "SquareSolver.h"
#include <stdio.h>


void sq_input (double *a, double *b, double *c){
    const int var_counts = 3;
    double *variables [var_counts] = {a, b, c};
    char variables_symb[var_counts] = {'a', 'b', 'c'};
    printf("Данная программа решает уравнения типа ax^2+bx+c=0, где a b c это числа \n");
    for ( int i = 0; i < var_counts; i++) {
        printf ("Введите %c:  ", variables_symb[i]);
        get_double (variables[i]);
    }
}

void li_input (double *b, double *c){
    const int var_counts = 2;
    double *variables [var_counts] = {b, c};
    char variables_symb[var_counts] = {'b', 'c'};
    printf("Данная программа решает уравнения типа bx+c=0, где b и c это числа \n");
    for ( int i = 0; i < var_counts; i++) {
        printf ("Введите %c:  ", variables_symb[i]);
        get_double (variables[i]);
    }
}

void output (MESSAGE_SOLUTION SolCount, double x1, double x2){
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





void get_double (double *a){
    while (scanf ("%lf", a)!=1 || getchar() != '\n'){
          printf ("Ошибка ввода, попробуйте еще раз  ");
          clean();
    }
}

void get_type (int *a){
    while (scanf ("%d", a) != 1 || getchar() != '\n' || ( *a == 1 || *a == 0) == false ){
          printf ("Ошибка ввода, для повторной попытки нажмите enter и попробуйте еще раз, ");
          clean();

    }
}


void clean(){
    while (getchar() != '\n') {;}

}
