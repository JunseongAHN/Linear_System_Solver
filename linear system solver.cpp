#include "stdafx.h"
#include "linear system solver.h"
#include <iostream>
#include <iomanip>
using namespace std;

int linearSystemSolver::findPivotPosition(long double**mat, const int pivot_row_n)
{
	for (int i = 0; i < COL; i++)
	{
		if (mat[pivot_row_n][i] != 0)
			return i;
	}
	return COL;
}
void linearSystemSolver::reduced(long double**mat, const int pivot_row_n, const int pivot_column_n)
{
	long double scalar;
	for (int i = 0; i < pivot_row_n; i++)
	{
			if (mat[i][pivot_column_n] != 0)
			{
				scalar = mat[pivot_row_n][pivot_column_n] / mat[i][pivot_column_n];
				scalarsMultiple(mat, i, scalar);
				reducedUpperPivot(mat, i,pivot_row_n, pivot_column_n);
			}
	}
}
void linearSystemSolver::reducedUpperPivot(long double**mat, const int row, const int pivot_row_n,const int pivot_column)
{
	for (int j = pivot_column; j < COL; j++)
	{
			if (mat[row][j] != 0)
				mat[row][j] -= mat[pivot_row_n][j];
	}
	matrixPrint(mat);
}
bool linearSystemSolver::pivotCheck(long double**mat, const int pivot_row_n, const int pivot_column_n)
{
	int atleast = 0;
	for (int i = pivot_row_n; i < ROW; i++)
	{
		if (mat[i][pivot_column_n] != 0)
		{
			atleast++;
			elementaryRowOp(mat, pivot_row_n, i);
		}
	}
	if (atleast == 0)
		return 0;
	else
		return 1;
}
void linearSystemSolver::elementaryRowOp(long double**mat, const int a, const int b)
{
	long double tmp;
	for (int i = 0; i < COL; i++)
	{
		tmp = mat[a][i];
		mat[a][i] = mat[b][i];
		mat[b][i] = tmp;
	}
}
void linearSystemSolver::scalars(long double**mat, const int pivot_row_n, const int pivot_column_n)
{
	int i;

	long double scalar;
	for (i = pivot_row_n; i < ROW; i++)
	{
		if (mat[i][pivot_column_n] != 0)
		{
			scalar = 1 / mat[i][pivot_column_n];
			scalarsMultiple(mat, i, scalar);
		}
	}
	MakePivotPosition(mat, pivot_row_n, pivot_column_n);
	
}
void linearSystemSolver::scalarsMultiple(long double**mat,const int row, long double scalar)
{
	for (int i = 0; i < COL; i++)
	{
		mat[row][i] *= scalar;
	}
	matrixPrint(mat);
}
void linearSystemSolver::MakePivotPosition(long double**mat, const int pivot_row, const int pivot_column)
{

	if (mat[pivot_row + 1][pivot_column] == 0)
		return;

	int j = pivot_column;
	for (int i = pivot_row + 1; i < ROW; i++)
	{
		if (mat[i][j] != 0)
		{
			for (j = pivot_column; j < COL; j++)
			{
				mat[i][j] -= mat[pivot_row][j];
			}
			j = pivot_column;
		}
	}
}
void linearSystemSolver::matrixPrint(long double**mat)
{
	std::cout.width(10);
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			cout << setw(10) << mat[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
void linearSystemSolver::rowEchelonForm(long double**mat)
{
	int pivot_poistion_row = 0, pivot_poistion_column = 0;

	while (pivot_poistion_row <= ROW - 1)
	{
		if (pivotCheck(mat, pivot_poistion_row, pivot_poistion_column))
		{

			matrixPrint(mat);
			scalars(mat, pivot_poistion_row, pivot_poistion_column);
			pivot_poistion_row++;
			pivot_poistion_column++;
		}
		else
			pivot_poistion_column++;
		matrixPrint(mat);
	}//echlon form done
}
void linearSystemSolver::reducedRowEchelonForm(long double**mat)
{

	rowEchelonForm(mat);
	//reduced start
	int pivot_poistion_row = 0, pivot_poistion_column = 0;
	int row = ROW - 1;
	do
	{
		pivot_poistion_column = findPivotPosition(mat, row);
		if (pivot_poistion_column != COL) {
			reduced(mat, row, pivot_poistion_column);
			scalarsMultiple(mat, row, 1.0 / mat[row][pivot_poistion_column]);
		}

		row--;
	} while (pivot_poistion_column != 0);

}