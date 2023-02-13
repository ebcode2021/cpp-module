#include <iostream>

#include "Point.hpp"

double	cal_len(Point const x, Point const y)
{
	double len;

	len =  sqrt(pow(y.get_y_value() - x.get_y_value(), 2) + pow(y.get_x_value() - x.get_x_value(), 2));
	return (len);
}

double	cal_area(double len1, double len2, double len3)
{
	double	s;
	double	area;

	s = (len1 + len2 + len3) / 2;

	area = sqrt(s * (s - len1) * (s - len2) * (s - len3));
	return (area);
}

bool	bsp(Point const a, Point const b, Point const c, Point const p)
{
	double	len1 = cal_len(a, b);
	double	len2 = cal_len(b, c);
	double	len3 = cal_len(c, a);

	double	inner_area = cal_area(cal_len(a, b), cal_len(b, c), cal_len(c,a));
	double	compare_area = cal_area(cal_len(a, b), cal_len(b, p), cal_len(p, a)) + \
							cal_area(cal_len(b, c), cal_len(c, p), cal_len(p, b)) + \
							cal_area(cal_len(c, a), cal_len(a, p), cal_len(p, c));
	
	if (inner_area < compare_area)
		return (false);
	return (true);
}