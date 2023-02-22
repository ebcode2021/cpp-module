#include <iostream>
#include "Cure.hpp"
#include "ICharacter.hpp"

// OCCF

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(const Cure& cure) : AMateria(cure._type)
{
}

Cure& Cure::operator=(const Cure& cure)
{
	if (this != &cure)
		this->_type = cure._type;
	return (*this);
}

Cure::~Cure()
{
}

AMateria* Cure::clone() const
{
	return (new Cure);
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals "<< target.getName() << "'s wounds *" << std::endl;
}
