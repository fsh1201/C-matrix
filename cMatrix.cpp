#include "cMatrix.h"
#include "j.h"

cMatrix::cMatrix(double** a, int m, int n)
{
	this->m = m;
	this->n = n;
	this->a = new double* [m];
	for (int i = 0; i < m; i++)
	{
		this->a[i] = new double[n];
		for (int j = 0; j < n; j++)
		{
			this->a[i][j] = a[i][j];
		}
	}
}

cMatrix::cMatrix()
{
	this->a = nullptr;
	this->m = 0;
	this->n = 0;
}

cMatrix::cMatrix(const cMatrix& p)
{
	this->m = p.m;
	this->n = p.n;
	this->a = new double* [m];
	for (int i = 0; i < m; i++)
	{
		this->a[i] = new double[n];
		for (int j = 0; j < n; j++)
		{
			this->a[i][j] = p.a[i][j];
		}
	}
}

double cMatrix::det()
{
	if (this->m != this->n)
	{
		cout << "不是方阵" << endl;
		exit(-2);
	}
	return hhlx(this->a, this->m);
}

cMatrix cMatrix::I()
{
	if (this->m != this->n)
	{
		cout << "不是方阵" << endl;
		exit(-3);
	}
	if (this->det() == 0)
	{
		cout << "矩阵行列式为0，逆不存在" << endl;
		exit(-4);
	}
	double** ai = inv(this->a, m);
	cMatrix c1(ai, m, n);
	return c1;
}

cMatrix cMatrix::T()
{
	cMatrix t;
	t.m = this->n;
	t.n = this->m;
	t.a = new double* [t.m];
	for (int i = 0; i < t.m; i++)
	{
		t.a[i] = new double[t.n];
		for (int j = 0; j < t.n; j++)
		{
			t.a[i][j] = this->a[j][i];
		}
	}
	return t;
}