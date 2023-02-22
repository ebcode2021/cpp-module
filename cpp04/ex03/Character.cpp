#include <iostream>
#include "Character.hpp"

Character::Character()
{
	this->_name = "character";
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(const Character& character)
{
	this->_name = character._name;
	for (int i = 0; i < 4; i++)
	{
		if (character._inventory[i])
			_inventory[i] = character._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
}

Character& Character::operator=(const Character& character)
{
	if (this != &character)
	{
		this->_name = character._name;
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i])
				delete this->_inventory[i];
			if (character._inventory[i])
				_inventory[i] = character._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
}

Character::Character(std::string const &name)
{
	this->_name = name;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

// method
std::string const & Character::getName() const
{
	return (this->_name);
}

void	Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			break ;
		}
	}
}

void	Character::unequip(int idx)
{
	if (!(idx >= 0 && idx <= 3))
		return ;
	if (_inventory[idx])
		_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (!(idx >= 0 && idx <= 3))
		return ;
	if (this->_inventory[idx])
		_inventory[idx]->use(target);
}