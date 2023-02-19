# include "WrongCat.hpp"

// OCCF

WrongCat::WrongCat()
{
	std::cout << "WrongCat :: default constructor" << std::endl;
	this->_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& wrongCat)
{
	std::cout << "Animal :: copy constructor" << std::endl;
	this->_type = wrongCat._type;
}

WrongCat& WrongCat::operator=(const WrongCat& wrongCat)
{
	std::cout << "WrongCat :: copy assignment operator" << std::endl;
	this->_type = wrongCat._type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat :: destructor" << std::endl;
}

// override
void	WrongCat::makesound() const
{
	std::cout << "보이면 안되는 메시지" << std::endl;
}