#include "SquareIO.h"
#include "SquareSolver.h"
#include <assert.h>
#include <stdio.h>

void flag_input(int argc, char *argv[], bool *line_flag, bool *test_flag){
    assert (argv != NULL);
    assert (line_flag != NULL);
    assert (test_flag != NULL);
    char *str = NULL;
    for(int i = 1; i < argc; i++){
        str = argv[i];
     if (str[0] == '-') {
         switch (str[1]) {
                case 'l':
                    *line_flag = true;
                    break;
                case 't' :
                    *test_flag = true;
                    break;
                default: fprintf (stderr,"���������� ���� � ��������� ������ \n");
            }
        }
    }
}

void input_coef (const int var_counts, double *variables[], char variables_symb[]){
    for (int i = 0; i < var_counts; i++) {
        printf ("������� %c:  ", variables_symb[i]);
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
    printf ("������ ��������� ������ ��������� ���� ax^2+bx+c=0, ��� a b c ��� ����� \n");
    input_coef(VAR_COUNTS, variables, variables_symb);
}

void li_input (double *b, double *c){
    assert (b != NULL);
    assert (c != NULL);

    const int VAR_COUNTS = 2;
    double *variables[VAR_COUNTS] = {b, c};
    char variables_symb[VAR_COUNTS] = {'b', 'c'};
    printf("������ ��������� ������ ��������� ���� bx+c=0, ��� b � c ��� ����� \n");
    input_coef(VAR_COUNTS, variables, variables_symb);
}

void output (int SolCount, double x1, double x2){
    switch(SolCount){
        case TWOSOL:
           printf ("��� �������: \n %10.15lf \n %10.15lf",x1,x2);
           break;
        case ONESOL:
           printf ("���� ������� %10.15lf", x1);
           break;
        case INFSOL:
           printf ("����������� ���������� �������");
           break;
        case NOSOL:
           printf ("��� �������");
           break;
           case UNKNOWN:
           printf ("UNKNOWN");
           break;
        default:
           printf ("ERRORS SWITCH");
           break;
    }
}

void get_double (double *a){
    assert (a != NULL);
    int tester = '0';
    while (scanf ("%lf", a) != 1 || ( (tester = getchar()) != '\n' && tester != EOF )){
          fprintf (stderr,"������ �����, ���������� ��� ���  ");
          clean();
    }

}



void clean(){
    while (getchar() != '\n') {;}

}
