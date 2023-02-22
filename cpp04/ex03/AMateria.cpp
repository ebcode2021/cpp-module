#include "AMateria.hpp"

// OCCF

AMateria::AMateria()
{
	this->_type = "materia";
}

AMateria::AMateria(const AMateria& materia)
{
	this->_type = materia._type;
}

AMateria& AMateria::operator=(const AMateria& materia)
{
	if (this != &materia)
		this->_type = materia._type;
	return (*this);
}

AMateria::~AMateria()
{
}

AMateria::AMateria(std::string const &type)
{
	this->_type = type;
}

// getter
std::string	const& AMateria::getType() const
{
	return (this->_type);
}

// method
void	AMateria::use(ICharacter& target)
{
	(void)target;
}