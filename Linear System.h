#pragma once

#include <iostream>
#include <vector>
#include "point.h"

using namespace std;

class LinearSystem
{
protected:
	int ROW;
	int COL;
	long double **mat_address;
	Point point[100];
public:
	~LinearSystem()
	{
		for (int i = 0; i < ROW; i++)
			delete[] mat_address[i];
		delete[] mat_address;
	}
	void setPoint();
	void setRow(int row) { this->ROW = COL; }
	void setColumn(int column) { this->ROW = COL; }
	void setLinearSystem_Points(long double ** mat);
	void setLinearSystem_arbitury(long double ** mat);
};