#pragma once
class point
{
private:
	double x;
	double y;
public:
	point(const double x1 = 0, const double y1 = 0);
	bool operator==(point p) const;
	double getX() const;
	double getY() const;
};

