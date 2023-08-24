#include "SquareSolver.h"

int main(){
int N = 0; // Переменная, отвечающая за номер сообщения
double a = 0, b = 0, c = 0, x1 = 0, x2 = 0; // ax^2+bx+c=0    input (&a, &b, &c);
testsquaresolver();
input(&a,&b,&c);
solutionsquare (a, b, c, &x1, &x2, &N);
output (N, x1, x2);
}    