#include "j.h"

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