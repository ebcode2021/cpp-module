#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class	Fixed
{
	private :
		int	_raw;
		static const int _fraction = 8;
	
	public :
		Fixed();
		Fixed(const int data);
		Fixed(const float data);
		Fixed(const Fixed&);
		Fixed& operator=(const Fixed&);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		/* comparison operators */
		bool operator >(const Fixed&) const;
		bool operator <(const Fixed&) const;
		bool operator >=(const Fixed&) const;
		bool operator <=(const Fixed&) const;
		bool operator ==(const Fixed&) const;
		bool operator !=(const Fixed&) const;

		/* arithmetic operators */
		Fixed operator +(const Fixed&) const;
		Fixed operator -(const Fixed&) const;
		Fixed operator *(const Fixed&) const;
		Fixed operator /(const Fixed&) const;

		/* increment/decrement operators */
		Fixed operator ++(int);
		Fixed& operator ++(void);
		Fixed operator --(int);
		Fixed& operator --(void);

		/* overloaded member functions */
		static Fixed& min(Fixed&, Fixed&);
		static const Fixed& min(const Fixed&, const Fixed&);
		static Fixed& max(Fixed&, Fixed&);
		static const Fixed& max(const Fixed&, const Fixed&);
};

std::ostream& operator << (std::ostream &out, const Fixed& fixed);

#endif