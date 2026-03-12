#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include "rect.h"
#include "point.h"
rect::rect(const point p1, const point p2, const point p3) {
	if (p1 == p2 || p2 == p3 || p1 == p3) {
		std::cout << "точки совпадают";
		abort();
	}
	if ((p1.getX() - p2.getX()) * (p3.getX() - p2.getX()) + (p1.getY() - p2.getY()) * (p3.getY() - p2.getY()) != 0 &&
		(p1.getX() - p3.getX()) * (p2.getX() - p3.getX()) + (p1.getY() - p3.getY()) * (p2.getY() - p3.getY()) != 0 &&
        (p2.getX() - p1.getX()) * (p3.getX() - p1.getX()) + (p2.getY() - p1.getY()) * (p3.getY() - p1.getY())){
		std::cout << "это не точки прямоугольника" << std::endl;
		abort();
	}
	a = point(p1.getX(), p1.getY());
	b = point(p2.getX(), p2.getY());
	c = point(p3.getX(), p3.getY());
    getSides();
}

void rect::getSides() {
    double dAB = std::pow(b.getX() - a.getX(), 2) + std::pow(b.getY() - a.getY(), 2);
    double dBC = std::pow(c.getX() - b.getX(), 2) + std::pow(c.getY() - b.getY(), 2);
    double dAC = std::pow(c.getX() - a.getX(), 2) + std::pow(c.getY() - a.getY(), 2);
    if (dAB >= dBC && dAB >= dAC) {
        side1 = std::sqrt(dBC);
        side2 = std::sqrt(dAC);
    }
    else if (dBC >= dAB && dBC >= dAC) {
        side1 = std::sqrt(dAB);
        side2 = std::sqrt(dAC);
    }
    else {
        side1 = std::sqrt(dAB);
        side2 = std::sqrt(dBC);
    }
}
double rect::getRad() {
    double diag = std::sqrt(side1 * side1 + side2 * side2);
    return diag / 2.0;
}
double rect:: getSq() {
    return M_PI*(side1 * side1 + side2 * side2) / 4;
}
