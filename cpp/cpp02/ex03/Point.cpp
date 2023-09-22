#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const float _x, const float _y) : x(_x), y(_y) {}

Point::Point(const Point& o) : x(o.x), y(o.y) {}

Point::~Point() {}

Point& Point::operator=(const Point& r) {
	x.setRawBits(r.x.getRawBits());
	y.setRawBits(r.y.getRawBits());
	return *this;
}
