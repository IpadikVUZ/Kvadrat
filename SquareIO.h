#ifndef SQUAREIO_H_INCLUDED
#define SQUAREIO_H_INCLUDED

//-----------------------------------------------------------------------------------
//! A main input function to type
//!
//! @param[in] argc argc from main
//! @param[int] *argv[] pointer to array of char arrays
//! @param[out] *line_flag  pointer to bool, that changing square or line
//! @param[out] *test_flag  pointer to bool, that changing turn on test or not
//-----------------------------------------------------------------------------------

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

void input_coef (const int VAR_COUNTS, double *variables[], char variables_symb[]);

//-----------------------------------------------------------------------------------
//! Function to output a message about the roots
//!
//! @param[in] VAR_COUNTS count of coefs( 2 or 3)
//! @param[in] *variables array of doubles pointers, when are entering
//! @param[in] *variables_symb array of variables_symb
//-----------------------------------------------------------------------------------

void output (int SolCount, double x1, double x2);


//-----------------------------------------------------------------------------------
//! Function for reading a double number from the console with input verification
//!
//! @param[out] a number
//!
//-----------------------------------------------------------------------------------

void get_double (double *a);


//-----------------------------------------------------------------------------------
//! Function for clearing the input buffer
//-----------------------------------------------------------------------------------


void clean();

#endif // SQUAREIO_H_INCLUDED
