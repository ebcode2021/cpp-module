#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <iomanip>

class	Fixed
{
	private :
		int	_raw;
		static const int _fraction = 8;

	public :
		Fixed();
		Fixed(const Fixed&);
		Fixed& operator=(const Fixed&);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif