#include <iostream>
#include "Ice.hpp"
#include "ICharacter.hpp"

// OCCF

Ice::Ice() : AMateria("ice")
{
}

Ice::Ice(const Ice& ice) : AMateria(ice._type)
{
}

Ice& Ice::operator=(const Ice& ice)
{
	if (this != &ice)
		this->_type = ice._type;
	return (*this);
}

Ice::~Ice()
{
}

AMateria* Ice::clone() const
{
	return (new Ice);
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
