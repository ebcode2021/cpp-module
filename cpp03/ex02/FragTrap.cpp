#include "FragTrap.hpp"

// OCCF

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "call FragTrap :: Default Constructor" << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "call FragTrap :: Name Constructor" << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap& fragTrap) : ClapTrap(fragTrap._name)
{
	std::cout << "call FragTrap :: Copy assignment operator" << std::endl;
	this->_hit_points = fragTrap._hit_points;
	this->_energy_points = fragTrap._energy_points;
	this->_attack_damage = fragTrap._attack_damage;
}

FragTrap& FragTrap::operator=(const FragTrap& fragTrap)
{
	std::cout << "call FragTrap :: Copy assignment operator" << std::endl;
	if (this != &fragTrap)
	{
		this->_name = fragTrap._name;
		this->_hit_points = fragTrap._hit_points;
		this->_energy_points = fragTrap._energy_points;
		this->_attack_damage = fragTrap._attack_damage;
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "call FragTrap :: Destructor" << std::endl;
}

// overriding function
void FragTrap::attack(const std::string& target)
{
	if (this->getHitPoints() <= 0 || this->getEnergyPoints() <= 0)
	{
		std::cout << "Not Enough HP || Not Enough EP" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->getName() << " attacks " << target \
				<< ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
	this->_energy_points -= 1;
}

// add function

void FragTrap::highFivesGuys()
{
	if (this->getHitPoints() <= 0 || this->getEnergyPoints() <= 0)
	{
		std::cout << "Not a status to guard" << std::endl;
		return ;
	}
	std::cout << "FragTrap! High Fives!" << std::endl;
}
