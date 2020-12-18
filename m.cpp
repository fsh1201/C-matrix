#include <iostream>
#include <cmath>
#include "cMatrix.h"
using namespace std;

int main()
{
	double** a = new double* [3];
	a[0] = new double[3];
	a[1] = new double[3];
	a[2] = new double[3];
	a[0][0] = 0.1;
	a[0][1] = 0.2;
	a[0][2] = 0.6;
	a[1][0] = 0.5;
	a[1][1] = 0.1;
	a[1][2] = 0.4;
	a[2][0] = 0.8;
	a[2][1] = 0.5;
	a[2][2] = 0.3;
	cMatrix c(a, 3, 3);
	cout << endl << c << endl;
	c = c.T();
	cout << c << endl;
	cMatrix c1 = c * c.I();
	cout << c1 << endl;

	c1 = c1 + 3;
	cout << c1 << endl;

	return 0;
}