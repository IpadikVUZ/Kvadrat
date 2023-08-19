#include <stdio.h>
#include <cmath>
void clean(){
        while (getchar()!='\n') {}
      }
int main(){
    double a,b,c; // ax^2+bx+c=0
    printf ("Введите коэффицент 2-й степени:  ");
    while (scanf ("%lf", &a)!=1){
          printf ("Ошибка ввода, попробуйте еще раз  ");
          clean();
    }
    printf ("Введите коэффицент 1-й степени:  ");
    while (scanf ("%lf", &b)!=1){
          printf ("Ошибка ввода, попробуйте еще раз  ");
          clean();
    }
    printf ("Введите свободный член:  ");
    while (scanf ("%lf", &c)!=1){
          printf ("Ошибка ввода, попробуйте еще раз  ");
          clean();
    }
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
            printf ( "%lf",-b/(2*a));
        }
        else if (discriminant<0){
            printf ("Решений нет");
        }
        else{
            printf ("%lf %lf", (-b+sqrt(discriminant))/(2*a), (-b-sqrt(discriminant))/(2*a));
        }
    }
}    