#pragma once
#include "point.h"
class rect
{
private:
	point a;
	point b;
	point c;
	double side1;
	double side2;
public:
	rect(const point p1, const point p2, const point p3);
	double getRad();
	double getSq();
	void getSides();
};

