# include "Brain.hpp"

// OCCF

Brain::Brain()
{
	std::cout << "Brain :: default constructor" << std::endl;
	this->_ideas[0] = "Nothing";
}

Brain::Brain(const Brain& brain)
{
	std::cout << "Brain :: copy constructor" << std::endl;
	this->_ideas[0] = brain._ideas[0];
}

Brain& Brain::operator=(const Brain& brain)
{
	std::cout << "Brain :: copy assignment operator" << std::endl;
	if (this != &brain)
		this->_ideas[0] = brain._ideas[0];
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain :: destructor" << std::endl;
}

Brain::Brain(std::string ideas)
{
	std::cout << "Brain :: idea constructor" << std::endl;
	this->_ideas[0] = ideas;
}

std::string Brain::getIdeas() const
{
	return (this->_ideas[0]);
}

void	Brain::setIdeas(const std::string idea)
{
	this->_ideas[0] = idea;
}