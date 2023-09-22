#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point {
	friend Fixed area(const Point&, const Point&, const Point&);
	friend bool bsp(Point const a, Point const b, Point const c, Point const point);
private:
	Fixed x;
	Fixed y;
public:
	Point();
	Point(const float, const float);
	Point(const Point&);
	Point& operator=(const Point&);
	~Point();
};



#endif
