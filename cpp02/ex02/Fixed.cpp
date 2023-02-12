#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_raw = 0;
}

Fixed::Fixed(const Fixed& prev)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = prev;
}

Fixed::Fixed(const int integer)
{
	std::cout << "Int constructor called" << std::endl;
	this->_raw = integer << this->_fraction;
}

Fixed::Fixed(const float data)
{
	std::cout << "Float constructor called" << std::endl;
	this->_raw = roundf(data * (1 << this->_fraction));
}

Fixed&	Fixed::operator=(const Fixed& prev)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_raw = prev.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	return (this->_raw);
}

void	Fixed::setRawBits(int const raw)
{
	this->_raw = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_raw / (1 << this->_fraction));
}

int	Fixed::toInt(void) const
{
	return (this->_raw >> this->_fraction);
}

/* assignment operators*/
std::ostream& operator<<(std::ostream &out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return out;
}