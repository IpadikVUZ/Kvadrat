#include "SquareIO.h"
#include "SquareSolver.h"
#include <assert.h>
#include <stdio.h>

void flag_input(const int argc, const char *argv[], MODE *mode, bool *need_tests) {

    assert (argv != NULL);
    assert (mode != NULL);
    assert (need_tests != NULL);

    *mode = UNKNOWN_MODE;
    char str[2];

    for(int i = 1; i < argc; i++) {
        assert (argv[i] != NULL);
        str[0] = *argv[i];
        str[1] = *(argv[i]+1);
        assert (str != NULL);
        if (str[0] == '-') {
             switch (str[1]) {

                case 'l':

                    if (*mode == UNKNOWN_MODE) {
                        *mode = LINE_MODE;
                        break;
                    }

                    else {
                        *mode = TOO_MANY_ARGS_MODE;
                        break;

                    }

                case 's':

                    if (*mode == UNKNOWN_MODE) {
                        *mode = SQUARE_MODE;
                        break;
                    }

                    else {
                        *mode = TOO_MANY_ARGS_MODE;
                        break;
                    }

                case 't':

                    *need_tests = true;
                    break;

                default:
                    fprintf (stderr,"Непонятный ключ в командной строке (-%c)\n", str[1]);
                    break;
            }
        }
    }
}

void input_coef (int var_counts, double *variables[], char variables_symb[]) {
    for (int i = 0; i < var_counts; i++) {
        printf ("Введите %c:  ", variables_symb[i]);
        get_double (variables[i]);
    }

}

void sq_input (double *a, double *b, double *c) {

    assert (a != NULL);
    assert (b != NULL);
    assert (c != NULL);

    const int VAR_COUNTS = 3;
    double *variables[VAR_COUNTS] = {a, b, c};
    char variables_symb[VAR_COUNTS] = {'a', 'b', 'c'};
    printf ("Данная программа решает уравнения типа ax^2+bx+c=0, где a b c это числа \n");
    input_coef (VAR_COUNTS, variables, variables_symb);
}

void li_input (double *b, double *c) {

    assert (b != NULL);
    assert (c != NULL);

    const int VAR_COUNTS = 2;
    double *variables[VAR_COUNTS] = {b, c};
    char variables_symb[VAR_COUNTS] = {'b', 'c'};
    printf ("Данная программа решает уравнения типа bx+c=0, где b и c это числа \n");
    input_coef (VAR_COUNTS, variables, variables_symb);
}

void output (int SolCount, double x1, double x2) {
    switch (SolCount) {
        case TWOSOL:
           printf ("Два решения: \n %.15lf \n %.15lf",x1,x2);
           break;

        case ONESOL:
           printf ("Одно решение %.15lf", x1);
           break;

        case INFSOL:
           printf ("Бесконечное количество решений");
           break;

        case NOSOL:
               printf ("Нет решений");
               break;

           case UNKNOWN:
               printf ("UNKNOWN MODE");
               break;

           case TOO_MANY_MODES:
                printf ("TOO MANY MODES!!!");

        default:
               printf ("ERRORS SWITCH");
               break;
    }
}

void get_double (double *a) {
    assert (a != NULL);
    int tester = '0';
    while (scanf ("%lf", a) != 1 || ( (tester = getchar()) != '\n' && tester != EOF )) {
          fprintf (stderr,"Ошибка ввода, попробуйте еще раз  ");
          clean();
    }

}



void clean() {
    while (getchar() != '\n') {;}

}
