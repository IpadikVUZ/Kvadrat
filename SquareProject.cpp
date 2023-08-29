#include "SquareSolver.h"
#include <TXLib.h>

int main(){
    MESSAGE_SOLUTION SolCount; // ѕеременна€, отвечающа€ за кол-во корней
    double a  = 0,
           b  = 0,
           c  = 0,
           x1 = 0,
           x2 = 0;// ax^2+bx+c=0
    //линейное или квадратное
    int type = -1;
    printf ("¬ведите 0, если хотите решить квадратное уравнение, если линейное,то 1: ");
    get_type (&type);
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
