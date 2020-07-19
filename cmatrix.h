#include <stdlib.h>
#include <math.h>
#include <stdio.h>

typedef struct {
	double** A;
	int m;
	int n;
} matrix;

/*行列式*/
double hhlx(double** arr, int na);
/*矩阵求逆*/
double** inv(double** a, int n);
/*矩阵相乘*/
double** AB(double** a, int ma, int na, double** b, int mb, int nb);
/*矩阵转置*/
double** TA(double** a, int ma, int na);

/*创建m行n列新矩阵*/
matrix* Mnew(int m, int n);
/*输出矩阵a*/
void Mprintf(matrix* a);
/*矩阵a的逆*/
matrix* Minv(matrix* a);
/*矩阵a与矩阵b相乘*/
matrix* Mmulti(matrix* a, matrix* b);
/*转置矩阵*/
matrix* Mtrans(matrix* a);
/*释放矩阵*/
void Mfree(matrix* a);
/*矩阵相加*/
matrix* Mplus(matrix* a, matrix* b);
/*矩阵相减*/
matrix* Mminus(matrix* a, matrix* b);
/*矩阵点乘*/
matrix* Mdotpro(matrix* a, matrix* b);
/*矩阵点除*/
matrix* Mdiv(matrix* a, matrix* b);