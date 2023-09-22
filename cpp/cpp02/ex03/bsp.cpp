#include "Point.hpp"

Fixed area(const Point& p1, const Point& p2, const Point& p3) {
	Fixed a(2);
	Fixed ret((p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y)) / a);
	if (ret < Fixed(0))
		ret = ret * Fixed(-1);
	return ret;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed a1 = area(a, b, point);
	Fixed b1 = area(b, c, point);
	Fixed c1 = area(a, c, point);
	Fixed d1 = area(a, b, c);
	if (a1 + b1 + c1 - d1 == Fixed(0))
		return true;
	return false;
}
