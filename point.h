#pragma once

#ifndef POINT_H
#define POINT_H

#include <iostream>

/*********************************************
* POINT
* A single position.
*********************************************/
class Point
{
public:
	// constructors
	Point() : x(0.0), y(0.0) {}
	Point(bool check) : x(0.0), y(0.0) {}
	Point(long double x, long double y);

	// getters
	long double getX()       const { return x; }
	long double getY()       const { return y; }

	// setters
	void setX(long double x);
	void setY(long double y);
	void addX(long double dx) { setX(getX() + dx); }
	void addY(long double dy) { setY(getY() + dy); }

private:
	long double x;           // horizontal position
	long double y;           // vertical position
};

// stream I/O useful for debugging
std::ostream & operator << (std::ostream & out, const Point & pt);
std::istream & operator >> (std::istream & in, Point & pt);

#endif // POINT_H
