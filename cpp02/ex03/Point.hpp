#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed _x;
		const Fixed _y;
		Point& operator=(const Point&);

	public:
		Point();
		Point(const float a, const float b);
		Point(const Point&);
		~Point();

		float	get_x_value(void) const;
		float	get_y_value(void) const;
};

#endif