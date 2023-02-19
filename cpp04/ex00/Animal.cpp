#include "Animal.hpp"

// OCCF

Animal::Animal()
{
	std::cout << "Aniaml :: default constructor" << std::endl;
	this->_type = "animal";
}

Animal::Animal(const Animal& animal)
{
	std::cout << "Animal :: copy constructor" << std::endl;
	this->_type = animal._type;
}

Animal& Animal::operator=(const Animal& animal)
{
	std::cout << "Animal :: copy assignment operator" << std::endl;
	if (this != &animal)
		this->_type = animal._type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal :: destructor" << std::endl;
}

// getter
std::string	Animal::getType() const
{
	return (this->_type);
}

// method
void	Animal::makeSound() const
{
	std::cout << "동물의 울음소리는 특정 지을 수 없습니다." << std::endl;
}