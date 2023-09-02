#include "SquareSolver.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>


MESSAGE_SOLUTION SolutionSquare (double a, double b, double c, double *x1, double *x2){

    assert (isfinite (a));
    assert (isfinite (b));
    assert (isfinite (c));

    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);

    if (DCompare (a, 0) == EQUAL) {
       return SolutionLine (b, c, x1);
    }
    else{
        double discriminant = b*b - 4*a*c;
        if (DCompare (discriminant, 0) == EQUAL){
            *x1 = -b / (2*a);
            if ( DCompare(*x1,0) == EQUAL) *x1 = 0;
            return ONESOL;
        }
        else if (DCompare (discriminant, 0) == SECONDLARGER)
            return NOSOL;
        else{
            double sqrtd = sqrt(discriminant);
            *x1 = (-b + sqrtd) / (2*a);
            *x2 = (-b - sqrtd) / (2*a);
            if (DCompare(*x1,0) == EQUAL)
                *x1 = 0;
            if (DCompare(*x2,0) == EQUAL)
                *x2 = 0;
            return TWOSOL;
        }
    }
}

MESSAGE_SOLUTION SolutionLine (double b, double c, double *x1){

    assert (isfinite (b));
    assert (isfinite (c));
    assert (x1 != NULL);

     if (DCompare (b, 0) == EQUAL){
         if (DCompare (c, 0) == EQUAL)
                return INFSOL;
         else
                return NOSOL;
     }
     else{
            if (DCompare(*x1,0) == EQUAL)
                *x1 = 0;
            *x1 = -c / b;
            return ONESOL;
     }
}

int DCompare (double a, double b){

    double epsilon = 1e-15;
    if (fabs(a - b) < epsilon)
        return EQUAL;
    else if (a - b > epsilon)
        return FIRSTLARGER;
    else
        return SECONDLARGER;
}
