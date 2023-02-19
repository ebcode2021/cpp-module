#include "Cat.hpp"

// OCCF

Cat::Cat() : Animal()
{
	std::cout << "Cat :: default constructor" << std::endl;
	this->_brain = new Brain("고양이는 참치캔이 먹고싶어요.");
	this->_type = "Cat";
}

Cat::Cat(const Cat& cat) : Animal()
{
	std::cout << "Animal :: copy constructor" << std::endl;
	this->_type = cat._type;
	this->_brain = new Brain(cat._brain->getIdeas());
	//this->_brain = new Brain(*(cat._brain));
}

Cat& Cat::operator=(const Cat& cat)
{
	std::cout << "Cat :: copy assignment operator" << std::endl;
	if (this != &cat)
	{
		this->_type = cat._type;
		delete this->_brain;
		this->_brain = new Brain(cat._brain->getIdeas());
		//*(this->_brain) = *(cat._brain);
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat :: destructor" << std::endl;
	delete this->_brain;
}

// override
void	Cat::makeSound() const
{
	std::cout << "먀먐냠먀먀ㅑ먀먐야먀먕" << std::endl;
}

// getter setter
std::string	Cat::getBrain() const
{
	return (this->_brain->getIdeas());
}

void	Cat::setBrain(const std::string idea)
{
	this->_brain->setIdeas(idea);
}