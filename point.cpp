#include "stdafx.h"
#include "point.h"
#include <cassert>

/******************************************
* POINT : CONSTRUCTOR WITH X,Y
* Initialize the point to the passed position
*****************************************/
Point::Point(long double x, long double y) : x(0.0), y(0.0)
{
	setX(x);
	setY(y);
}

/*******************************************
* POINT : SET X
* Set the x position if the value is within range
*******************************************/
void Point::setX(long double x)
{
	this->x = x;
}

/*******************************************
* POINT : SET Y
* Set the y position if the value is within range
*******************************************/
void Point::setY(long double y)
{
	this->y = y;
}

/******************************************
* POINT insertion
*       Display coordinates on the screen
*****************************************/
std::ostream & operator << (std::ostream & out, const Point & pt)
{
	out << "(" << pt.getX() << ", " << pt.getY() << ")";
	return out;
}

/*******************************************
* POINT extraction
*       Prompt for coordinates
******************************************/
std::istream & operator >> (std::istream & in, Point & pt)
{
	long double x;
	long double y;
	in >> x >> y;

	pt.setX(x);
	pt.setY(y);

	return in;
}