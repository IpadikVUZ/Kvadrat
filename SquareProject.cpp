#include "SquareSolver.h"
#include <TXLib.h>

int main(int argc, char *argv[]){

    MESSAGE_SOLUTION SolCount = UNKNOWN; // Переменная, отвечающая за кол-во корней
    double a  = 0,
           b  = 0,
           c  = 0,
           x1 = 0,
           x2 = 0;// ax^2+bx+c=0
    int type = 0;

    if(argv[1] != NULL)
        type = flag_input (*argv[1]);

    if (type == 0){
        TestSquareSolver();     //флаг на тест
        sq_input (&a, &b, &c);
        SolCount = SolutionSquare (a, b, c, &x1, &x2);
        output (SolCount, x1, x2);
    }
    else {
        TestSolutionLine();
        li_input (&b, &c);
        SolCount = SolutionSquare (a, b, c, &x1, &x2);
        output (SolCount, x1, x2);
    }

}

