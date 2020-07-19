#include "cmatrix.h"

/*ÐÐÁÐÊ½*/
double hhlx(double** arr, int na)
{
	if (na == 1)
	{
		return arr[0][0];
	}
	else
	{
		double s = 0;
		for (int i = 0; i < na; i++)
		{
			double** arr1;
			arr1 = (double**)malloc((na - 1) * sizeof(double));
			for (int i = 0; i < na - 1; i++)
			{
				arr1[i] = (double*)malloc((na - 1) * sizeof(double));
			}
			for (int j = 1; j < na; j++)
			{
				for (int k = 0; k < na - 1; k++)
				{
					if (k >= i)
					{
						arr1[j - 1][k] = arr[j][k + 1];
					}
					else
					{
						arr1[j - 1][k] = arr[j][k];
					}
				}
			}
			s = s + hhlx(arr1, na - 1) * pow(-1, i) * arr[0][i];
			for (int i = 0; i < na - 1; i++)
			{
				free(arr1[i]);
			}
			free(arr1);
		}
		return s;
	}
}

/*Äæ¾ØÕó*/
double** inv(double** a, int n)
{
	double det = hhlx(a, n);
	double** as;
	as = (double**)malloc(n * sizeof(double));
	for (int i = 0; i < n; i++)
	{
		as[i] = (double*)malloc(n * sizeof(double));
	}
	for (int is = 0; is < n; is++)
	{
		for (int js = 0; js < n; js++)
		{
			double** ab;
			ab = (double**)malloc((n - 1) * sizeof(double));
			for (int i = 0; i < n - 1; i++)
			{
				ab[i] = (double*)malloc((n - 1) * sizeof(double));
			}
			for (int i = 0; i < n - 1; i++)
			{
				for (int j = 0; j < n - 1; j++)
				{
					if (i >= is)
					{
						if (j >= js)
							ab[i][j] = a[i + 1][j + 1];
						else
							ab[i][j] = a[i + 1][j];
					}
					else
					{
						if (j >= js)
							ab[i][j] = a[i][j + 1];
						else
							ab[i][j] = a[i][j];
					}
				}
			}
			as[js][is] = pow(-1, (double)is + (double)js) * hhlx(ab, n - 1);

			for (int i = 0; i < n - 1; i++)
			{
				free(ab[i]);
			}
			free(ab);
		}
	}
	double** ai;
	ai = (double**)malloc(n * sizeof(double));
	for (int i = 0; i < n; i++)
	{
		ai[i] = (double*)malloc(n * sizeof(double));
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			ai[i][j] = as[i][j] / det;
		}
	}
	return ai;
}

/*¾ØÕóÏà³Ë*/
double** AB(double** a, int ma, int na, double** b, int mb, int nb)
{
	if (na != mb)
	{
		printf("¼ÆËã´íÎó£¡");
		return NULL;
	}
	else
	{
		double** ab;
		ab = (double**)malloc(ma * sizeof(double));
		for (int i = 0; i < ma; i++)
		{
			ab[i] = (double*)malloc(nb * sizeof(double));
		}
		for (int i = 0; i < ma; i++)
		{
			for (int j = 0; j < nb; j++)
			{
				ab[i][j] = 0;
				for (int k = 0; k < na; k++)
				{
					ab[i][j] = ab[i][j] + a[i][k] * b[k][j];
				}
			}
		}
		return ab;
	}
}

/*¾ØÕó×ªÖÃ*/
double** TA(double** a, int ma, int na)
{
	double** ta;
	ta = (double**)malloc(na * sizeof(double));
	for (int i = 0; i < na; i++)
	{
		ta[i] = (double*)malloc(ma * sizeof(double));
	}
	for (int i = 0; i < na; i++)
	{
		for (int j = 0; j < ma; j++)
		{
			ta[i][j] = a[j][i];
		}
	}
	return ta;
}

matrix* Mnew(int m, int n)
{
	matrix* a;
	a = (matrix*)malloc(sizeof(matrix));
	a->A = (double**)malloc(m * sizeof(double));
	for (int i = 0; i < m; i++)
	{
		a->A[i] = (double*)malloc(n * sizeof(double));
	}
	a->m = m;
	a->n = n;
	return a;
}

void Mprintf(matrix* a)
{
	for (int i = 0; i < a->m; i++)
	{
		for (int j = 0; j < a->n; j++)
		{
			printf("%f ", a->A[i][j]);
		}
		printf("\n");
	}
}

matrix* Minv(matrix* a)
{
	matrix* ai;
	ai = (matrix*)malloc(sizeof(matrix));
	ai->A = inv(a->A, a->m);
	ai->m = a->m;
	ai->n = a->m;
	return ai;
}

matrix* Mmulti(matrix* a, matrix* b)
{
	matrix* ab;
	ab = (matrix*)malloc(sizeof(matrix));
	ab->A = AB(a->A, a->m, a->n, b->A, b->m, b->n);
	ab->m = a->m;
	ab->n = b->n;
	return ab;
}

matrix* Mtrans(matrix* a)
{
	matrix* at;
	at = (matrix*)malloc(sizeof(matrix));
	at->A = TA(a->A, a->m, a->n);
	at->m = a->n;
	at->n = a->m;
	return at;
}

matrix* Mplus(matrix* a, matrix* b)
{
	matrix* c;
	c = (matrix*)malloc(sizeof(matrix));
	c->A = (double**)malloc(a->m * sizeof(double));
	for (int i = 0; i < a->m; i++)
	{
		c->A[i] = (double*)malloc(a->n * sizeof(double));
	}
	c->m = a->m;
	c->n = a->n;
	for (int i = 0; i < a->m; i++)
	{
		for (int j = 0; j < a->n; j++)
		{
			c->A[i][j] = a->A[i][j] + b->A[i][j];
		}
	}
	return c;
}

matrix* Mminus(matrix* a, matrix* b)
{
	matrix* c;
	c = (matrix*)malloc(sizeof(matrix));
	c->A = (double**)malloc(a->m * sizeof(double));
	for (int i = 0; i < a->m; i++)
	{
		c->A[i] = (double*)malloc(a->n * sizeof(double));
	}
	c->m = a->m;
	c->n = a->n;
	for (int i = 0; i < a->m; i++)
	{
		for (int j = 0; j < a->n; j++)
		{
			c->A[i][j] = a->A[i][j] - b->A[i][j];
		}
	}
	return c;
}

matrix* Mdotpro(matrix* a, matrix* b)
{
	matrix* c;
	c = (matrix*)malloc(sizeof(matrix));
	c->A = (double**)malloc(a->m * sizeof(double));
	for (int i = 0; i < a->m; i++)
	{
		c->A[i] = (double*)malloc(a->n * sizeof(double));
	}
	c->m = a->m;
	c->n = a->n;
	for (int i = 0; i < a->m; i++)
	{
		for (int j = 0; j < a->n; j++)
		{
			c->A[i][j] = (a->A[i][j]) * (b->A[i][j]);
		}
	}
	return c;
}

matrix* Mdiv(matrix* a, matrix* b)
{
	matrix* c;
	c = (matrix*)malloc(sizeof(matrix));
	c->A = (double**)malloc(a->m * sizeof(double));
	for (int i = 0; i < a->m; i++)
	{
		c->A[i] = (double*)malloc(a->n * sizeof(double));
	}
	c->m = a->m;
	c->n = a->n;
	for (int i = 0; i < a->m; i++)
	{
		for (int j = 0; j < a->n; j++)
		{
			c->A[i][j] = a->A[i][j] / b->A[i][j];
		}
	}
	return c;
}

void Mfree(matrix* a)
{
	for (int i = 0; i < a->m; i++)
	{
		free(a->A[i]);
	}
	free(a->A);
	free(a);
}