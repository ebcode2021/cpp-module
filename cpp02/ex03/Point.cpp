#include "Point.hpp"

Point::Point() : _x(Fixed()), _y(Fixed()){}

Point::Point(const float a, const float b) : _x(Fixed(a)), _y(Fixed(b)){}

Point::Point(const Point& point) : _x(point._x), _y(point._y){}

Point& Point::operator=(const Point& point)
{
	return (*this);
}

Point::~Point(){}

float	Point::get_x_value(void) const
{
	return (this->_x.toFloat());
}

float	Point::get_y_value(void) const
{
	return (this->_y.toFloat());
}
