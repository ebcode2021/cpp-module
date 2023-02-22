# include "Cat.hpp"

// OCCF

Cat::Cat()
{
	std::cout << "Cat :: default constructor" << std::endl;
	this->_type = "Cat";
}

Cat::Cat(const Cat& cat)
{
	std::cout << "Cat :: copy constructor" << std::endl;
	this->_type = cat._type;
}

Cat& Cat::operator=(const Cat& cat)
{
	std::cout << "Cat :: copy assignment operator" << std::endl;
	if (this != &cat)
		this->_type = cat._type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat :: destructor" << std::endl;
}

// override
void	Cat::makeSound() const
{
	std::cout << "먀먐냠먀먀ㅑ먀먐야먀먕" << std::endl;
}