#include "SquareSolver.h"
#include <assert.h>
#include <stdio.h>

int flag_input(char a){
    if(a == 'l') return 1;
    else return 0;
}

void input_coef (const int VAR_COUNTS, double *variables[], char variables_symb[]){
    for (int i = 0; i < VAR_COUNTS; i++) {
        printf ("Введите %c:  ", variables_symb[i]);
        get_double (variables[i]);
    }

}

void sq_input (double *a, double *b, double *c){
    assert (a != NULL);
    assert (b != NULL);
    assert (c != NULL);

    const int VAR_COUNTS = 3;
    double *variables[VAR_COUNTS] = {a, b, c};
    char variables_symb[VAR_COUNTS] = {'a', 'b', 'c'};
    printf ("Данная программа решает уравнения типа ax^2+bx+c=0, где a b c это числа \n");
    input_coef(VAR_COUNTS, variables, variables_symb);
}

void li_input (double *b, double *c){
    assert (b != NULL);
    assert (c != NULL);

    const int VAR_COUNTS = 2;
    double *variables[VAR_COUNTS] = {b, c};
    char variables_symb[VAR_COUNTS] = {'b', 'c'};
    printf("Данная программа решает уравнения типа bx+c=0, где b и c это числа \n");
    input_coef(VAR_COUNTS, variables, variables_symb);
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
    assert (a != NULL);
    char tester = '0';
    while (scanf ("%lf", a) != 1 || (tester = getchar()) != '\n' && tester != 'EOF'){
          fprintf (stderr,"Ошибка ввода, попробуйте еще раз  ");
          clean();
    }
}



void clean(){
    while (getchar() != '\n') {;}

}
