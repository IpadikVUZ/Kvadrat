#include <stdio.h>
#include <cmath>
int main(){
    double a,b,c; // ax^2+bx+c=0
    printf("Введите кофициент 2-й степени:  ");
    scanf("%lf", &a);
    printf("Ввелите кофициент 1-й степени:  ");
    scanf("%lf", &b);
    printf("Введите свободный член:  ");
    scanf("%lf", &c);
    
    if(a==0) {
        if(b==0){
            if(c==0) printf("x любое");
            else printf("решений нет");
        }
        else printf("%lf",-c/b);
    }
    else{
    double discriminant=b*b-4*a*c;
    if(discriminant==0) printf( "%lf",-b/(2*a));
    else if(discriminant<0)printf("решений нет");
    else printf("%lf %lf" ,(-b+sqrt(discriminant))/(2*a),(-b-sqrt(discriminant))/(2*a));
    }
            }