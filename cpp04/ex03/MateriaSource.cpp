#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

// OCCF

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& source)
{
	for (int i = 0; i < 4; i++)
	{
		if (source._inventory[i])
			_inventory[i] = source._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& source)
{
	if (this != &source)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i])
				delete this->_inventory[i];
			if (source._inventory[i])
				_inventory[i] = source._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
}

void	MateriaSource::learnMateria(AMateria *materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = materia;
			break ;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	if (type.compare("ice"))
		return (new Ice);
	if (type.compare("cure"))
		return (new Cure);
	return (0);
}