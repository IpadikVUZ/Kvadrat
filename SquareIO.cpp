#include "SquareSolver.h"
#include <stdio.h>


void sq_input (double *a, double *b, double *c){
    const int var_counts = 3;
    double *variables [var_counts] = {a, b, c};
    char variables_symb[var_counts] = {'a', 'b', 'c'};
    printf("������ ��������� ������ ��������� ���� ax^2+bx+c=0, ��� a b c ��� ����� \n");
    for ( int i = 0; i < var_counts; i++) {
        printf ("������� %c:  ", variables_symb[i]);
        get_double (variables[i]);
    }
}

void li_input (double *b, double *c){
    const int var_counts = 2;
    double *variables [var_counts] = {b, c};
    char variables_symb[var_counts] = {'b', 'c'};
    printf("������ ��������� ������ ��������� ���� bx+c=0, ��� b � c ��� ����� \n");
    for ( int i = 0; i < var_counts; i++) {
        printf ("������� %c:  ", variables_symb[i]);
        get_double (variables[i]);
    }
}

void output (MESSAGE_SOLUTION SolCount, double x1, double x2){
    switch(SolCount){
        case TWOSOL:
           printf ("��� �������: %lf � %lf",x1,x2);
           break;
        case ONESOL:
           printf ("���� ������� %lf", x1);
           break;
        case INFSOL:
           printf ("����������� ���������� �������");
           break;
        case NOSOL:
           printf ("��� �������");
           break;
    }
}





void get_double (double *a){
    while (scanf ("%lf", a)!=1 || getchar() != '\n'){
          printf ("������ �����, ���������� ��� ���  ");
          clean();
    }
}

void get_type (int *a){
    while (scanf ("%d", a) != 1 || getchar() != '\n' || ( *a == 1 || *a == 0) == false ){
          printf ("������ �����, ��� ��������� ������� ������� enter � ���������� ��� ���, ");
          clean();

    }
}


void clean(){
    while (getchar() != '\n') {;}

}
