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
	return (!(abs(x - p.x) < DBL_EPSILON) && !(abs(y - p.y) < DBL_EPSILON));
}
bool point::operator!=(const point p) const {
	return !(*this == p);
}


