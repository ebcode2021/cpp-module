#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_raw = 0;
}

Fixed::Fixed(const Fixed& prev)
{
	std::cout << "Copy constructor called" << std::endl;
	//this->_raw = prev.getRawBits();
	*this = prev;
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
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_raw);
}

void	Fixed::setRawBits(int const raw)
{
	this->_raw = raw;
}