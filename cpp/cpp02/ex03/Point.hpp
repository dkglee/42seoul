#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

Fixed area(const Point&, const Point&, const Point&);
bool bsp(Point const a, Point const b, Point const c, Point const point);

class Point {
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
