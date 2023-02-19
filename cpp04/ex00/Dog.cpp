# include "Dog.hpp"

// OCCF

Dog::Dog()
{
	std::cout << "Dog :: default constructor" << std::endl;
	this->_type = "Dog";
}

Dog::Dog(const Dog& dog)
{
	std::cout << "Animal :: copy constructor" << std::endl;
	this->_type = dog._type;
}

Dog& Dog::operator=(const Dog& dog)
{
	std::cout << "Dog :: copy assignment opeDogor" << std::endl;
	if (this != &dog)
	{
		this->_type = dog._type;
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog :: destructor" << std::endl;
}

// override
void	Dog::makeSound() const
{
	std::cout << "왈왈온오ㄹㅇㅇㅇㅇㅇ러ㅗ아ㅗ아ㅗ알와로아왈" << std::endl;
}