#include "WrongAnimal.hpp"

// OCCF

WrongAnimal::WrongAnimal()
{
	std::cout << "Aniaml :: default constructor" << std::endl;
	this->_type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal& wrongAnimal)
{
	std::cout << "WrongAnimal :: copy constructor" << std::endl;
	this->_type = wrongAnimal._type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& wrongAnimal)
{
	std::cout << "WrongAnimal :: copy assignment operator" << std::endl;
	this->_type = wrongAnimal._type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal :: destructor" << std::endl;
}

// getter
std::string	WrongAnimal::getType() const
{
	return (this->_type);
}

// method
void	WrongAnimal::makeSound() const
{
	std::cout << "이 메시지가 연속해서 보인다는 것은 무언가 잘못된 것이겠지요." << std::endl;
}