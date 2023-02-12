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
		bool operator >(const Fixed&);
		bool operator <(const Fixed&);
		bool operator >=(const Fixed&);
		bool operator <=(const Fixed&);
		bool operator ==(const Fixed&);
		bool operator !=(const Fixed&);

		/* arithmetic operators */
		Fixed& operator +(const Fixed&);
		Fixed& operator -(const Fixed&);
		Fixed& operator *(const Fixed&);
		Fixed& operator /(const Fixed&);

		/* increment/decrement operators */
		void operator ++(int);
		Fixed& operator ++(void);
		void operator --(int);
		Fixed& operator --(void);


		/* overloaded member functions */
		static Fixed& min(Fixed&, Fixed&);
		static Fixed& min(const Fixed&, const Fixed&);
		static Fixed& max(Fixed&, Fixed&);
		static Fixed& max(const Fixed&, const Fixed&);
};

std::ostream& operator << (std::ostream &out, const Fixed& fixed);

#endif