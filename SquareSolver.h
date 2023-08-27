enum MESSAGE{
    TWOSOL = 0,
    ONESOL = 1,
    INFSOL = 2,
    NOSOL = 3
};

//-----------------------------------------------------------------------------------
//! ������ ��������� ��������� ax^2+bx+c=0
//!
//! @param[in] a a-����������
//! @param[in] b b-����������
//! @param[in] c c-����������
//! @param[out] x1 ��������� �� ������ �������
//! @param[out] x2 ��������� �� ������ �������
//-----------------------------------------------------------------------------------

int solutionsquare (double a, double b, double c, double *x1,  double *x2);

//-----------------------------------------------------------------------------------
//! ������ �������� ��������� bx+c=0
//!
//! @param[in] b b-����������
//! @param[in] c c-����������
//! @param[out] x1 ��������� �� �������
//-----------------------------------------------------------------------------------

int solutionline (double b, double c, double *x1);

//-----------------------------------------------------------------------------------
//! ������� ��� ����� ���� ������������ ���� double
//!
//! @param[out] a ��������� �� ������ �����
//! @param[out] b ��������� �� ������ �����
//! @param[out] c ��������� �� ������ �����
//-----------------------------------------------------------------------------------

void input (double *a, double *b, double *c);

//-----------------------------------------------------------------------------------
//! ������� ��� ������ ��������� � ������
//!
//! @param[in] SolCount ����� ���������
//! @param[in] x1 ������ ������
//! @param[in] x2 ������ ������
//-----------------------------------------------------------------------------------

void output (int n, double x1, double x2);

//-----------------------------------------------------------------------------------
//! ������� ��� ���������� ����� ���� double � ������� � ��������� �����
//!
//! @param[out] a ��������� �� ����������, � ������� �������� �����
//-----------------------------------------------------------------------------------

void getdouble (double *a);

//-----------------------------------------------------------------------------------
//! ������� ��� ������� ������ �����
//-----------------------------------------------------------------------------------

void clean();

//-----------------------------------------------------------------------------------
//! ������� ��� �������� �������� ������ ������� solutionline
//-----------------------------------------------------------------------------------

void testsolutionline();

//-----------------------------------------------------------------------------------
//! ������� ��� �������� �������� ������ ������� solutionsquare
//-----------------------------------------------------------------------------------

void testsolutionsquare();

//-----------------------------------------------------------------------------------
//! �������� ��� ����������� �������� ������� ssolutionline � solutionsquare
//-----------------------------------------------------------------------------------

void testsquaresolver();
