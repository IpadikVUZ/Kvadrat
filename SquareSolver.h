#ifndef SQUARE_SOLVER_H
#define SQUARE_SOLVER_H
enum MESSAGE_SOLUTION{
    TWOSOL = 0,
    ONESOL = 1,
    INFSOL = 2,
    NOSOL = 3,
    UNKNOWN = 4
};

enum DOUBLE_COMPARSION{
    EQUAL = 0,
    FIRSTLARGER = 1,
    SECONDLARGER = 2
};

//-----------------------------------------------------------------------------------
//! Solves the quadratic equations ax^2+bx+c=0
//!
//! @param[in] a a-coefficient
//! @param[in] b b-coefficient
//! @param[in] c c-coefficient
//! @param[out] x1 Pointer to the first solution
//! @param[out] x2 Pointer to the second solution
//! @return Number of roots (from MESSAGE_SOLUTION enum)
//-----------------------------------------------------------------------------------

MESSAGE_SOLUTION SolutionSquare (double a, double b, double c, double *x1, double *x2);    //enum type

//-----------------------------------------------------------------------------------
//! Solves linear equations bx+c=0
//!
//! @param[in] b b-coefficient
//! @param[in] c c-coefficient
//! @param[out] x1 Pointer to the solution
//! @return number of roots
//-----------------------------------------------------------------------------------

MESSAGE_SOLUTION SolutionLine (double b, double c, double *x1);

//-----------------------------------------------------------------------------------
//! Function for comparing numbers of type double
//!
//! @param[out] a Pointer to the variable into which the number is entered
//-----------------------------------------------------------------------------------

int DCompare (double a, double b);



#endif
