#include "point.h"
point::point(const double x1, const double y1){
	x = x1;
	y = y1;
}
double point::getX()const {
	return x;
}
double point::getY()const {
	return y;
}
bool point::operator==(const point p) const {
	return (!(x - p.x < 0 || x - p.x>0) && !(y - p.y < 0 || y - p.y>0));
}
bool point::operator!=(const point p) const {
	return !(*this == p);
}


