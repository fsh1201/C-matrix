#include "cmatrix.h"

int main()
{
	matrix* d;
	d = Mnew(3, 3);
	d->A[0][0] = 1;
	d->A[0][1] = 2;
	d->A[1][0] = 3;
	d->A[1][1] = 4;
	d->A[0][2] = 6.5;
	d->A[1][2] = 0;
	d->A[2][0] = 0;
	d->A[2][1] = 8;
	d->A[2][2] = 3.6;
	
	Minit(d);
	printf("输入的矩阵为：\n");
	Mprintf(d);
	printf("矩阵逆为：\n");
	Mprintf(d->inv);
	printf("矩阵转置为：\n");
	Mprintf(d->T);

	printf("矩阵转置的逆：\n");
	Mprintf(d->T->inv);
	printf("矩阵逆的转置：\n");
	Mprintf(d->inv->T);
	Mprintf("矩阵转置的逆的转置：\n");
	Mprintf(d->T->inv->T);
	printf("矩阵转置的逆的转置的逆的转置：\n");
	Mprintf(d->T->inv->T->inv->T);
	printf("矩阵逆的逆：\n");
	Mprintf(d->inv->inv);
	printf("转置的转置的逆的逆：\n");
	Mprintf(d->T->T->inv->inv);
	printf("逆的逆的转置的转置：\n");
	Mprintf(d->inv->inv->T->T);
	printf("矩阵的行列式：%f\n", d->det);
	printf("矩阵的逆的行列式：%f\n", d->inv->det);
	printf("矩阵的逆的转置的行列式：%f\n", d->inv->T->det);
	printf("矩阵的转置的逆的转置的逆的转置的逆的逆的行列式：%f\n", d->T->inv->T->inv->T->inv->inv->det);
	printf("矩阵的转置的逆的行列式：%f\n", d->T->inv->det);
	printf("矩阵的逆的转置的逆的行列式：%f\n", d->inv->T->inv->det);
	printf("矩阵的转置的逆的逆的行列式：%f\n", d->T->inv->inv->det);

	Mfree(d);

	return 0;
}