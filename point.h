#pragma once
class point
{
private:
    /**
    * @brief x - координата точки по оси OX
    */
	double x;
    /**
    * @brief y - координата точки по оси OY
    */
	double y;
public:
     /**
    * @brief конструктор, создает точку, с координатами x,y
    * @param x - координата точки по оси OX
    * @param y - координата точки по оси OY
    */
	point(const double x1 = 0, const double y1 = 0);
     /**
    * @brief оператор проверяет совпадают ли точки
    */
	bool operator==(point p) const;
     /**
    * @brief оператор проверяет отличаются ли точки
    */
	bool operator!=(point p) const;
  /**
    * @brief получение координаты x
    * @return x
    */
	double getX() const;
    /**
    * @brief получение координаты y
    * @return y
    */
	double getY() const;
};


