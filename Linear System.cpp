#include "stdafx.h"
#include "Linear System.h"

using namespace std;

void LinearSystem::setPoint()
{
	long double x, y;
	int j;
	for (int i = 0; i < ROW; i++)
	{
		cout << i + 1 << " Put in x and y with space: ";
		cin >> x >> y;
		point[i].setX(x);
		point[i].setY(y);
	}
}
void LinearSystem::setLinearSystem_Points(long double **mat)
{
	//for polynomial
	int j;
	//Make a linear system by pluging points in in polynomial : P(COL-2)
	for (int i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL - 1; j++)
		{
			mat[i][j] = pow(point[i].getX(), COL - 2 - j);
		}
		mat[i][j] = point[i].getY();
	}
}

void LinearSystem::setLinearSystem_arbitury(long double **mat)
{
	int i, j;
	printf("Enter the matrix of order %dx%d:\n", ROW, COL);
	for (i = 0; i < ROW; i++) {
		cout << "First ROW " << i + 1 << " entry:";
		for (j = 0; j < COL; j++)
			cin >> mat[i][j];
	}
}