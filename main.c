#include "cmatrix.h"

int main()
{
	matrix* d;
	d = Mnew(2, 2);
	d->A[0][0] = 1;
	d->A[0][1] = 2;
	d->A[1][0] = 3;
	d->A[1][1] = 4;
	
	printf("输入的矩阵为：\n");
	Mprintf(d);
	matrix* dinv, * dt, * ddt, * ddinv;
	dinv = Minv(d);
	printf("矩阵逆为：\n");
	Mprintf(dinv);
	dt = Mtrans(d);
	printf("矩阵转置为：\n");
	Mprintf(dt);
	ddt = Mmulti(d, dt);
	printf("矩阵与转置相乘：\n");
	Mprintf(ddt);
	ddinv = Mmulti(d, dinv);
	printf("矩阵与逆相乘为：\n");
	Mprintf(ddinv);

	Mfree(d);
	Mfree(dt);
	Mfree(dinv);
	Mfree(ddt);
	Mfree(ddinv);

	return 0;
}