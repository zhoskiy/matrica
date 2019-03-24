
#include "pch.h"
#include <iostream>
#include <time.h>
using namespace std;

void gm(int **mas, int **p, int i, int j, int m) {
	int ki, kj, di, dj;
	int  t = m - 1;
	di = 0;
	for (ki = 0; ki <t; ki++)
	{ 
		if (ki == i) di = 1;
		dj = 0;
		for (kj = 0; kj < t; kj++) 
		{ 
			if (kj == j) dj = 1;
			p[ki][kj] = mas[ki + di][kj + dj];
		}
	}
}
int det(int **matr, int m)
{
	int i=0, j=0, k=1, d=0, n;
	int **p;
	p = new int*[m];
	for (i = 0; i < m; i++)
		p[i] = new int[m];
	n = m - 1;
	if (m == 1)
	{
		d = matr[0][0];
		return (d);
	}
	if (m == 2)
	{
		d = matr[0][0] * matr[1][1] - matr[1][0] * matr[0][1];
		return (d);
	}
	if (m > 2)
	{
		for (i=0; i < m; i++)
		{
			gm(matr, p, i, 0, m);
			d = d + k * matr[i][0] * det(p, n);
			k = -k;
		}
	}
	return (d);

	
}

int main()
{
	setlocale(LC_ALL, "russian");
	int n;
	cout << "Введите число n , чтобы создать матрицу n на n " << endl;
	cin >> n;
	int **matr;
	matr = new int*[n];
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		matr[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			matr[i][j] = rand() % 10;
			cout << matr[i][j] << " ";
		}
		cout << endl;
	}
	int d= det(matr, n);
	cout << "определитель = " << d << endl;
	if(d<=0)
	{
		cout << "Простое число отрицательным или 0 быть не может" << endl;
		return 0;
	}
	for (int t = 2; t < sqrt(d) + 1; t++)
	{
		if (d%t == 0)
		cout << "Это непростое число" << endl;
		else
			cout << "Это простое число" << endl;
		return 0;
	}

}
