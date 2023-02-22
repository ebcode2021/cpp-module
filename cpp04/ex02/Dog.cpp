# include "Dog.hpp"

// OCCF

Dog::Dog() : Animal()
{
	std::cout << "Dog :: default constructor" << std::endl;
	Brain *brain = new Brain("산책 주인 떨어진 고기");
	this->_brain = brain;
	this->_type = "Dog";
}

Dog::Dog(const Dog& dog) : Animal()
{
	std::cout << "Dog :: copy constructor" << std::endl;
	this->_type = dog._type;
	this->_brain = new Brain(*(dog._brain));
}

Dog& Dog::operator=(const Dog& dog)
{
	std::cout << "Dog :: copy assignment opeDogor" << std::endl;
	if (this != &dog)
	{
		this->_type = dog._type;
		*(this->_brain) = *(dog._brain);
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog :: destructor" << std::endl;
	delete this->_brain;
}

// override
void	Dog::makeSound() const
{
	std::cout << "왈왈온오ㄹㅇㅇㅇㅇㅇ러ㅗ아ㅗ아ㅗ알와로아왈" << std::endl;
}

// getter setter
std::string	Dog::getBrain() const
{
	return (this->_brain->getIdeas());
}

void	Dog::setBrain(const std::string idea)
{
	this->_brain->setIdeas(idea);
}