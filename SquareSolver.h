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
//! A main input function to type
//!
//! @param[in] argc argc from main
//! @param[int] *argv[] pointer to array of char arrays
//! @param[out] *line_flag  pointer to bool, that changing square or line
//! @param[out] *test_flag  pointer to bool, that changing turn on test or not
//----------------------------------------------------------------------------------- !!!!!!!!!!!!!!!!!!!!!!!!!!!

void flag_input(int argc, char* argv[], bool *line_flag, bool *test_flag);

//-----------------------------------------------------------------------------------
//! A function for entering three time periods of type double in square function
//!
//! @param[out] a Pointer to the first number
//! @param[out] b Pointer to the second number
//! @param[out] c Pointer to the third number
//-----------------------------------------------------------------------------------

void sq_input (double *a, double *b, double *c);

//-----------------------------------------------------------------------------------
//! A function for entering three time periods of type double
//!
//! @param[out] b Pointer to the first number
//! @param[out] c Pointer to the second number
//-----------------------------------------------------------------------------------

void li_input (double *a, double *b);

//-----------------------------------------------------------------------------------
//! A function that introduces a given number of initial coefficients of an equation
//!
//! @param[out] b Pointer to the first number
//! @param[out] c Pointer to the second number
//-----------------------------------------------------------------------------------

void input_coef (const int VAR_COUNTS, double *variables[], char *variables_symb[]);

//-----------------------------------------------------------------------------------
//! Function to output a message about the roots
//!
//! @param[in] VAR_COUNTS count of coefs( 2 or 3)
//! @param[in] *variables array of doubles pointers, when are entering
//! @param[in] *variables_symb array of variables_symb
//-----------------------------------------------------------------------------------

void output (MESSAGE_SOLUTION SolCount, double x1, double x2);

//-----------------------------------------------------------------------------------
//! Function for comparing numbers of type double
//!
//! @param[out] a Pointer to the variable into which the number is entered
//-----------------------------------------------------------------------------------

int DCompare (double a, double b);

//-----------------------------------------------------------------------------------
//! Function for reading a double number from the console with input verification
//!
//! @param[out] a number
//!
//-----------------------------------------------------------------------------------

void get_double (double *a);

//-----------------------------------------------------------------------------------
//! Function for reading a int number of type from the console with input verification
//!
//! @param[out] a number
//!
//-----------------------------------------------------------------------------------

void get_type (int *a);

//-----------------------------------------------------------------------------------
//! Function for clearing the input buffer
//-----------------------------------------------------------------------------------

void clean();

//-----------------------------------------------------------------------------------
//! Function to check the correctness of the SolutionLine function
//-----------------------------------------------------------------------------------

void TestSolutionLine();

//-----------------------------------------------------------------------------------
//! Function to check the correctness of the SolutionSquare function
//-----------------------------------------------------------------------------------

void TestSolutionSquare();

//-----------------------------------------------------------------------------------
//! A function for complex verification of ssolutionline and SolutionSquare functions
//-----------------------------------------------------------------------------------

void TestSquareSolver();

#endif
