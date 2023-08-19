#include <stdio.h>
#include <cmath>

void clean(){
    while (getchar()!='\n') {;}
}

void vvod (double &a){
    while (scanf ("%lf", &a)!=1){
          printf ("Ошибка ввода, попробуйте еще раз  ");
          clean();
    }
}

void solution (double a, double b, double c){
    if (a==0) {
        if (b==0){
            if (c==0){
                printf ("X любое");
            }
            else{
                printf ("Решений нет");
            }
        }
        else{
            printf ("%lf",-c/b);
        }
    }
    else{
        double discriminant=b*b-4*a*c;
        if (discriminant==0){
            printf ("%lf",-b/(2*a));
        }
        else if (discriminant<0){
            printf ("Решений нет");
        }
        else{
            printf ("%lf %lf", (-b+sqrt(discriminant))/(2*a), (-b-sqrt(discriminant))/(2*a));
        }
    }
}

int main(){
    double a = 0, b = 0, c = 0; // ax^2+bx+c=0
    printf ("Введите коэффицент 2-й степени:  ");
    vvod (a);
    printf ("Введите коэффицент 1-й степени:  ");
    vvod (b);
    printf ("Введите свободный член:  ");
    vvod (c);
    solution(a,b,c);
}    