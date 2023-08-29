#include "SquareSolver.h"
#include <TXLib.h>

int main(){
    MESSAGE_SOLUTION SolCount; // Переменная, отвечающая за кол-во корней
    double a  = 0,
           b  = 0,
           c  = 0,
           x1 = 0,
           x2 = 0;// ax^2+bx+c=0
    int type = -1;

    main_input(&type);

    if (type == 0){
        TestSquareSolver();
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
//добавить флаги обработка аргумента коммандной стоки
