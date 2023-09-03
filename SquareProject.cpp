#include "SquareSolver.h"
#include "SquareTester.h"
#include "SquareIO.h"
#include <assert.h>
#include <TXLib.h>

int main (const int argc, const char *argv[]) {
    double a  = 0,
           b  = 0,
           c  = 0,
           x1 = 0,
           x2 = 0;

    MESSAGE_SOLUTION SolCount = UNKNOWN;

    MODE mode = UNKNOWN_MODE;
    bool need_tests = false;

    flag_input (argc, argv, &mode, &need_tests);

    switch (mode) {

        case LINE_MODE:

            if (need_tests)
                TestSolutionLine();

            li_input (&b, &c);

            SolCount = SolutionLine (b, c, &x1);

            output (SolCount, x1, 0);

            break;

        case SQUARE_MODE:

            if (need_tests)
                TestSolutionSquare();

            sq_input (&a, &b, &c);

            SolCount = SolutionSquare (a, b, c, &x1, &x2);

            output (SolCount, x1, x2);

            break;


        case TOO_MANY_ARGS_MODE:

            output (TOO_MANY_MODES, 0, 0);

            break;

        case UNKNOWN_MODE:

            output (UNKNOWN, 0, 0);

            break;

        default:

            assert (mode != UNKNOWN_MODE);

    }







    /*if (line_mode) {

        if (need_tests)
            TestSolutionLine();

        li_input (&b, &c);
        SolCount = SolutionLine (b, c, &x1);
        output (SolCount, x1, x2);
    }
    else
    {
        if (need_tests)
            TestSquareSolver();

        sq_input (&a, &b, &c);
        SolCount = SolutionSquare (a, b, c, &x1, &x2);
        output (SolCount, x1, x2);
    }
    */
}

