#pragma once
#include "Linear System.h"

class linearSystemSolver : public LinearSystem
{
private:
	
public:
	void scalarsMultiple(long double** mat, const int row, long double scalar);
	void scalars(long double** mat, const int pivot_row_n, const int pivot_column_n);
	void MakePivotPosition(long double** mat, const int pivot_row, const int pivot_column);
	void elementaryRowOp(long double** mat, const int a, const int b);
	bool pivotCheck(long double** mat, const int pivot_row_n, const int pivot_column_n);
	int findPivotPosition(long double** mat, const int pivot_row_n);
	void reduced(long double** mat, const int pivot_row_n, const int pivot_column_n);
	void reducedUpperPivot(long double** mat, const int row, const int pivot_row_n, const int pivot_column);
	void matrixPrint(long double** mat);
	void rowEchelonForm(long double** mat);
	void reducedRowEchelonForm(long double** mat);
};