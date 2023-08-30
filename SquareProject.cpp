#include "SquareSolver.h"
#include "SquareTester.h"
#include "SquareIO.h"
#include <TXLib.h>

int main(int argc, char *argv[]){

    MESSAGE_SOLUTION SolCount = UNKNOWN; // Переменная, отвечающая за кол-во корней
    double a  = 0,
           b  = 0,
           c  = 0,
           x1 = 0,
           x2 = 0;// ax^2+bx+c=0
    bool line_flag = false;
    bool test_flag = false;
    flag_input (argc, argv, &line_flag, &test_flag);

    if (line_flag == false){
        if (test_flag == true)
            TestSquareSolver();
        sq_input (&a, &b, &c);
        SolCount = SolutionSquare (a, b, c, &x1, &x2);
        output (SolCount, x1, x2);
    }
    else {
        if (test_flag == true)
            TestSolutionLine();
        li_input (&b, &c);
        SolCount = SolutionLine (b, c, &x1);
        output (SolCount, x1, x2);
    }

}

