#include "SquareSolver.h"
#include <TXLib.h>

int main(){
    int SolCount = 0; // Переменная, отвечающая за номер сообщения
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0; // ax^2+bx+c=0    input (&a, &b, &c);
    testsquaresolver();
    input(&a, &b, &c);
    SolCount = solutionsquare (a, b, c, &x1, &x2);
    output (SolCount, x1, x2);
}
