#pragma once
#include <iostream>
#include <vector>
using namespace std;

class cMatrix
{
private:
	double** a;
	int m;
	int n;
public:
	cMatrix(double** a, int m, int n);
	cMatrix();
	cMatrix(const cMatrix& p);
	~cMatrix()
	{
		for (int i = 0; i < m; i++)
		{
			delete[] this->a[i];
		}
		delete[] this->a;
	}

	vector<double> operator[](int k)
	{
		return vector<double>(this->a[k], this->a[k] + n);
	}

	cMatrix operator+(cMatrix p)
	{
		cMatrix m1;
		m1.m = this->m;
		m1.n = this->n;
		m1.a = new double* [m1.m];
		for (int i = 0; i < m1.m; i++)
		{
			m1.a[i] = new double[m1.n];
			for (int j = 0; j < m1.n; j++)
			{
				m1.a[i][j] = this->a[i][j] + p.a[i][j];
			}
		}
		return m1;
	}

	cMatrix operator+(double p)
	{
		cMatrix m1;
		m1.m = this->m;
		m1.n = this->n;
		m1.a = new double* [m1.m];
		for (int i = 0; i < m1.m; i++)
		{
			m1.a[i] = new double[m1.n];
			for (int j = 0; j < m1.n; j++)
			{
				m1.a[i][j] = this->a[i][j] + p;
			}
		}
		return m1;
	}

	cMatrix operator-(cMatrix p)
	{
		cMatrix m1;
		m1.m = this->m;
		m1.n = this->n;
		m1.a = new double* [m1.m];
		for (int i = 0; i < m1.m; i++)
		{
			m1.a[i] = new double[m1.n];
			for (int j = 0; j < m1.n; j++)
			{
				m1.a[i][j] = this->a[i][j] - p.a[i][j];
			}
		}
		return m1;
	}

	cMatrix operator-(double p)
	{
		cMatrix m1;
		m1.m = this->m;
		m1.n = this->n;
		m1.a = new double* [m1.m];
		for (int i = 0; i < m1.m; i++)
		{
			m1.a[i] = new double[m1.n];
			for (int j = 0; j < m1.n; j++)
			{
				m1.a[i][j] = this->a[i][j] - p;
			}
		}
		return m1;
	}

	cMatrix operator/(cMatrix p)
	{
		cMatrix m1;
		m1.m = this->m;
		m1.n = this->n;
		m1.a = new double* [m1.m];
		for (int i = 0; i < m1.m; i++)
		{
			m1.a[i] = new double[m1.n];
			for (int j = 0; j < m1.n; j++)
			{
				m1.a[i][j] = this->a[i][j] / p.a[i][j];
			}
		}
		return m1;
	}

	cMatrix operator/(double p)
	{
		cMatrix m1;
		m1.m = this->m;
		m1.n = this->n;
		m1.a = new double* [m1.m];
		for (int i = 0; i < m1.m; i++)
		{
			m1.a[i] = new double[m1.n];
			for (int j = 0; j < m1.n; j++)
			{
				m1.a[i][j] = this->a[i][j] / p;
			}
		}
		return m1;
	}

	cMatrix operator*(cMatrix p)
	{
		if (this->n != p.m)
		{
			cout << "¾ØÕóÎÞ·¨Ïà³Ë" << endl;
			exit(-1);
		}
		cMatrix m1;
		m1.m = this->m;
		m1.n = this->n;
		m1.a = new double* [m1.m];
		for (int i = 0; i < m1.m; i++)
		{
			m1.a[i] = new double[m1.n];
		}
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				m1.a[i][j] = 0;
				for (int k = 0; k < n; k++)
				{
					m1.a[i][j] += this->a[i][k] * p.a[k][j];
				}
			}
		}
		return m1;
	}

	cMatrix operator*(double p)
	{
		cMatrix m1;
		m1.m = this->m;
		m1.n = this->n;
		m1.a = new double* [m1.m];
		for (int i = 0; i < m1.m; i++)
		{
			m1.a[i] = new double[m1.n];
			for (int j = 0; j < m1.n; j++)
			{
				m1.a[i][j] = this->a[i][j] * p;
			}
		}
		return m1;
	}

	void operator=(cMatrix p)
	{
		if (this->a)
		{
			for (int i = 0; i < this->m; i++)
			{
				delete[] this->a[i];
			}
			delete[] this->a;
		}
		m = p.m;
		n = p.n;
		a = new double* [m];
		for (int i = 0; i < m; i++)
		{
			a[i] = new double[n];
			for (int j = 0; j < n; j++)
			{
				a[i][j] = p.a[i][j];
			}
		}
	}

	double det();
	cMatrix I();
	cMatrix T();

	friend ostream& operator<<(ostream& out, const cMatrix& c)
	{
		for (int i = 0; i < c.m; i++)
		{
			for (int j = 0; j < c.n; j++)
			{
				out << c.a[i][j] << " ";
			}
			out << endl;
		}
		return out;
	}
};

