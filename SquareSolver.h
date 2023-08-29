#ifndef SQUARE_SOLVER_H
#define SQUARE_SOLVER_H

enum MESSAGE_SOLUTION{
TWOSOL = 0,
ONESOL = 1,
INFSOL = 2,
NOSOL = 3
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
//! @return Number of roots
//-----------------------------------------------------------------------------------

int solutionsquare (double a, double b, double c, double *x1, double *x2);

//-----------------------------------------------------------------------------------
//! Solves linear equations bx+c=0
//!
//! @param[in] b b-coefficient
//! @param[in] c c-coefficient
//! @param[out] x1 Pointer to the solution
//! @return number of roots
//-----------------------------------------------------------------------------------

int solutionline (double b, double c, double *x1);

//-----------------------------------------------------------------------------------
//! A function for entering three time periods of type double
//!
//! @param[out] a Pointer to the first number
//! @param[out] b Pointer to the second number
//! @param[out] c Pointer to the third number
//-----------------------------------------------------------------------------------

void input (double *a, double *b, double *c);

//-----------------------------------------------------------------------------------
//! Function to output a message about the roots
//!
//! @param[in] SolCount message number
//! @param[in] x1 first root
//! @param[in] x2 second root
//-----------------------------------------------------------------------------------

void output (int n, double x1, double x2);

//-----------------------------------------------------------------------------------
//! Function for comparing numbers of type double
//!
//! @param[out] a Pointer to the variable into which the number is entered
//-----------------------------------------------------------------------------------

int DCompare (double a, double b);

//-----------------------------------------------------------------------------------
//! Function for reading a double number from the console with input verification
//!
//! @param[in] a first number
//! @param[in] b the second number
//!
//! @return is the number responsible for which of the entered numbers is greater
//-----------------------------------------------------------------------------------

void getdouble (double *a);

//-----------------------------------------------------------------------------------
//! Function for clearing the input buffer
//-----------------------------------------------------------------------------------

void clean();

//-----------------------------------------------------------------------------------
//! Function to check the correctness of the solutionline function
//-----------------------------------------------------------------------------------

void testsolutionline();

//-----------------------------------------------------------------------------------
//! Function to check the correctness of the solutionsquare function
//-----------------------------------------------------------------------------------

void testsolutionsquare();

//-----------------------------------------------------------------------------------
//! A function for complex verification of ssolutionline and solutionsquare functions
//-----------------------------------------------------------------------------------

void testsquaresolver();

#endif